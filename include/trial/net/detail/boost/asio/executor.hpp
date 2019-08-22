#ifndef TRIAL_NET_DETAIL_BOOST_ASIO_EXECUTOR_HPP
#define TRIAL_NET_DETAIL_BOOST_ASIO_EXECUTOR_HPP

///////////////////////////////////////////////////////////////////////////////
//
// Copyright (C) 2019 Bjorn Reese <breese@users.sourceforge.net>
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
///////////////////////////////////////////////////////////////////////////////

#include <boost/asio/async_result.hpp>
#include <trial/net/detail/boost/asio/execution_context.hpp>

namespace trial
{
namespace net
{

class executor
{
public:
    executor() = default;
    executor(const executor&) = default;
    executor(executor&&) = default;
    executor& operator=(const executor&) = default;
    executor& operator=(executor&&) = default;

    template <typename Executor>
    executor(Executor& context)
        : excontext(std::addressof(context))
    {
    }

    operator execution_context&() const
    {
        return *excontext;
    }

    operator execution_context&()
    {
        return *excontext;
    }

    execution_context& context() const
    {
        return *excontext;
    }

    template <typename... Args>
    void defer(Args&&... args) const
    {
        // Best approximation to defer
        excontext->dispatch(std::forward<Args>(args)...);
    }

    template <typename... Args>
    void dispatch(Args&&... args) const
    {
        excontext->dispatch(std::forward<Args>(args)...);
    }

    template <typename... Args>
    void post(Args&&... args) const
    {
        excontext->post(std::forward<Args>(args)...);
    }

private:
    execution_context *excontext = nullptr;
};

//-----------------------------------------------------------------------------

template <typename CompletionToken, typename Signature>
using async_result = boost::asio::async_result<typename boost::asio::handler_type<CompletionToken, Signature>::type>;

template <typename CompletionToken, typename Signature>
using async_result_t = typename async_result<CompletionToken, Signature>::type;

template <typename CompletionToken, typename Signature>
struct async_completion
{
    async_completion(CompletionToken& token)
        : completion_handler(token),
          result(completion_handler)
    {
    }

    using handler_type = typename boost::asio::handler_type<CompletionToken, Signature>::type;
    handler_type completion_handler;
    boost::asio::async_result<handler_type> result;
};

//-----------------------------------------------------------------------------
// Extensions
//-----------------------------------------------------------------------------

namespace extension
{

namespace detail
{

template <typename T>
constexpr auto select_getter(int) -> decltype(std::declval<T>().get_io_service(), int())
{
    return 2;
}

template <typename T>
constexpr auto select_getter(int) -> decltype(std::declval<T>().context(), int())
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
        return t.context();
    }
};

template <typename T>
struct overloader<T, 2>
{
    static executor get_executor(T&& t)
    {
        return t.get_io_service();
    }
};

} // namespace detail

template <typename T>
auto get_executor(T&& t) -> executor
{
    return detail::overloader<T, detail::select_getter<T>(0)>::get_executor(std::forward<decltype(t)>(t));
}

} // namespace extension

//-----------------------------------------------------------------------------
// Free functions
//-----------------------------------------------------------------------------

template <typename Executor, typename CompletionToken>
auto defer(Executor&& executor,
           CompletionToken&& token) -> decltype(executor.defer(std::forward<decltype(token)>(token)))
{
    return executor.defer(std::forward<decltype(token)>(token));
}

template <typename Executor, typename CompletionToken>
auto dispatch(Executor&& executor,
              CompletionToken&& token) -> decltype(executor.dispatch(std::forward<decltype(token)>(token)))
{
    return executor.dispatch(std::forward<decltype(token)>(token));
}

template <typename Executor, typename CompletionToken>
auto post(Executor&& executor,
          CompletionToken&& token) -> decltype(executor.post(std::forward<decltype(token)>(token)))
{
    return executor.post(std::forward<decltype(token)>(token));
}

} // namespace net
} // namespace trial

#endif // TRIAL_NET_DETAIL_BOOST_ASIO_EXECUTOR_HPP
