#ifndef TRIAL_NET_DETAIL_BOOST_ASIO_INTERNET_HPP
#define TRIAL_NET_DETAIL_BOOST_ASIO_INTERNET_HPP

///////////////////////////////////////////////////////////////////////////////
//
// Copyright (C) 2019 Bjorn Reese <breese@users.sourceforge.net>
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
///////////////////////////////////////////////////////////////////////////////

namespace trial
{
namespace net
{
namespace extension
{

template <typename Resolver, typename String, typename ResolveHandler>
void async_resolve(Resolver resolver, String&& host, String&& service, ResolveHandler&& handler)
{
    typename decltype(resolver)::element_type::query query(host, service);
    resolver->async_resolve(query,
                            std::forward<decltype(handler)>(handler));
}

} // namespace extension
} // namespace net
} // namespace trial

#endif // TRIAL_NET_DETAIL_BOOST_ASIO_INTERNET_HPP
