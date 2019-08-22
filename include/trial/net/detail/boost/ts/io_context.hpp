#ifndef TRIAL_NET_DETAIL_BOOST_TS_IO_CONTEXT_HPP
#define TRIAL_NET_DETAIL_BOOST_TS_IO_CONTEXT_HPP

///////////////////////////////////////////////////////////////////////////////
//
// Copyright (C) 2019 Bjorn Reese <breese@users.sourceforge.net>
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
///////////////////////////////////////////////////////////////////////////////

#include <boost/asio/ts/io_context.hpp>

namespace trial
{
namespace net
{

using io_context = boost::asio::io_context;

//-----------------------------------------------------------------------------
// Extensions
//-----------------------------------------------------------------------------

namespace extension
{

template <typename T>
auto get_context(T& t) -> io_context&
{
    return t.context();
}

} // namespace extension

} // namespace net
} // namespace trial

#endif // TRIAL_NET_DETAIL_BOOST_TS_IO_CONTEXT_HPP
