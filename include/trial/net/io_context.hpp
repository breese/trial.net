#ifndef TRIAL_NET_IO_CONTEXT_HPP
#define TRIAL_NET_IO_CONTEXT_HPP

///////////////////////////////////////////////////////////////////////////////
//
// Copyright (C) 2019 Bjorn Reese <breese@users.sourceforge.net>
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
///////////////////////////////////////////////////////////////////////////////

#include <trial/net/detail/config.hpp>

#if defined(TRIAL_NET_USE_BOOST_TS)
# include <trial/net/detail/boost/ts/io_context.hpp>
#else
# include <trial/net/detail/boost/asio/io_context.hpp>
#endif

#endif // TRIAL_NET_IO_CONTEXT_HPP
