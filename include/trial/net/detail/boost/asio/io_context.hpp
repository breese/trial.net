#ifndef TRIAL_NET_DETAIL_BOOST_ASIO_IO_CONTEXT_HPP
#define TRIAL_NET_DETAIL_BOOST_ASIO_IO_CONTEXT_HPP

///////////////////////////////////////////////////////////////////////////////
//
// Copyright (C) 2019 Bjorn Reese <breese@users.sourceforge.net>
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
///////////////////////////////////////////////////////////////////////////////

#include <trial/net/detail/boost/asio/execution_context.hpp>
#include <trial/net/detail/boost/asio/executor.hpp>

namespace trial
{
namespace net
{

using io_context = net::execution_context;

//-----------------------------------------------------------------------------
// Extensions
//-----------------------------------------------------------------------------

namespace extension
{

template <typename T>
auto get_context(T& t) -> io_context&
{
    return t.get_io_service();
}

template <>
inline auto get_context(executor& t) -> io_context&
{
    return static_cast<io_context&>(t);
}

template <>
inline auto get_context(const executor& t) -> io_context&
{
    return static_cast<io_context&>(t);
}

} // namespace extension

} // namespace net
} // namespace trial

#endif // TRIAL_NET_DETAIL_BOOST_ASIO_IO_CONTEXT_HPP
