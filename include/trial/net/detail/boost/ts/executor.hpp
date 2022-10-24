#ifndef TRIAL_NET_DETAIL_TS_EXECUTOR_HPP
#define TRIAL_NET_DETAIL_TS_EXECUTOR_HPP

///////////////////////////////////////////////////////////////////////////////
//
// Copyright (C) 2019 Bjorn Reese <breese@users.sourceforge.net>
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
///////////////////////////////////////////////////////////////////////////////

#include <boost/asio/ts/executor.hpp>
#include <boost/asio/async_result.hpp>

namespace trial
{
namespace net
{

#if BOOST_VERSION >= 107400
	// V1.74.0 - The any_io_executor type alias has been introduced as the default runtime-polymorphic executor for all I/O objects. 
    using executor = boost::asio::any_io_executor;
#else
    using executor = boost::asio::executor;
#endif


using boost::asio::defer;
using boost::asio::dispatch;
using boost::asio::post;

//-----------------------------------------------------------------------------

template <typename CompletionToken, typename Signature>
using async_result = boost::asio::async_result<typename std::decay<CompletionToken>::type, Signature>;

template <typename CompletionToken, typename Signature>
using async_result_t = typename async_result<CompletionToken, Signature>::return_type;

template <typename CompletionToken, typename Signature>
using async_completion = boost::asio::async_completion<CompletionToken, Signature>;

//-----------------------------------------------------------------------------
// Extensions
//-----------------------------------------------------------------------------

namespace extension
{

namespace detail
{
template <typename T>
constexpr auto select_getter(int) -> decltype(std::declval<T>().get_executor(), int())
{
    return 1;
}

template <typename T>
constexpr bool select_getter(...)
{
    return 0;
}

template <typename T, int>
struct overloader
{
    static executor get_executor(T&& t)
    {
        return executor(std::forward<decltype(t)>(t));
    }
};

template <typename T>
struct overloader<T, 1>
{
    static executor get_executor(T&& t)
    {
        return t.get_executor();
    }
};

} // namespace detail

template <typename T>
auto get_executor(T&& t) -> executor
{
    return detail::overloader<T, detail::select_getter<T>(0)>::get_executor(std::forward<decltype(t)>(t));
}

} // namespace extension

} // namespace net
} // namespace trial

#endif // TRIAL_NET_DETAIL_TS_EXECUTOR_HPP
