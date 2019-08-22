#ifndef TRIAL_NET_DETAIL_BOOST_ASIO_EXECUTION_CONTEXT_HPP
#define TRIAL_NET_DETAIL_BOOST_ASIO_EXECUTION_CONTEXT_HPP

///////////////////////////////////////////////////////////////////////////////
//
// Copyright (C) 2019 Bjorn Reese <breese@users.sourceforge.net>
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
///////////////////////////////////////////////////////////////////////////////

#include <boost/asio/io_service.hpp>

namespace trial
{
namespace net
{

using execution_context = boost::asio::io_service;

} // namespace net
} // namespace trial

#endif // TRIAL_NET_DETAIL_BOOST_ASIO_EXECUTION_CONTEXT_HPP
