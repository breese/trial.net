#ifndef TRIAL_NET_DETAIL_BOOST_TS_INTERNET_HPP
#define TRIAL_NET_DETAIL_BOOST_TS_INTERNET_HPP

///////////////////////////////////////////////////////////////////////////////
//
// Copyright (C) 2019 Bjorn Reese <breese@users.sourceforge.net>
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
///////////////////////////////////////////////////////////////////////////////

#include <boost/asio/ts/internet.hpp>

namespace trial
{
namespace net
{
namespace extension
{

template <typename Resolver, typename String, typename ResolveHandler>
void async_resolve(Resolver resolver, String&& host, String&& service, ResolveHandler&& handler)
{
    resolver->async_resolve(std::forward<decltype(host)>(host),
                            std::forward<decltype(service)>(service),
                            std::forward<decltype(handler)>(handler));
}

} // namespace extension
} // namespace net
} // namespace trial

#endif // TRIAL_NET_DETAIL_BOOST_TS_INTERNET_HPP
