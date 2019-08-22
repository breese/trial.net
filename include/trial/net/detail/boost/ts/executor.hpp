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

using executor = boost::asio::executor;

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

template <typename T>
auto get_executor(T&& t) -> decltype(t.get_executor())
{
    return t.get_executor();
}

} // namespace extension

} // namespace net
} // namespace trial

#endif // TRIAL_NET_DETAIL_TS_EXECUTOR_HPP
