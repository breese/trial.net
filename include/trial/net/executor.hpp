#ifndef TRIAL_NET_EXECUTOR_HPP
#define TRIAL_NET_EXECUTOR_HPP

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
# include <trial/net/detail/boost/ts/executor.hpp>
#else
# include <trial/net/detail/boost/asio/executor.hpp>
#endif

#endif // TRIAL_NET_EXECUTOR_HPP
