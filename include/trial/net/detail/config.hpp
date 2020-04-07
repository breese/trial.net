#ifndef TRIAL_NET_DETAIL_CONFIG_HPP
#define TRIAL_NET_DETAIL_CONFIG_HPP

///////////////////////////////////////////////////////////////////////////////
//
// Copyright (C) 2019 Bjorn Reese <breese@users.sourceforge.net>
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
///////////////////////////////////////////////////////////////////////////////

#include <boost/version.hpp>
#if BOOST_VERSION >= 107000
# define TRIAL_NET_USE_BOOST_TS
#else
# define TRIAL_NET_USE_BOOST_ASIO
#endif

#endif // TRIAL_NET_DETAIL_CONFIG_HPP
