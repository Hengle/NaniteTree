//
// Copyright (c) 2016-2019 Vinnie Falco (vinnie dot falco at gmail dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/boostorg/beast
//

#ifndef BOOST_BEAST_WEBSOCKET_DETAIL_HYBI13_IPP
#define BOOST_BEAST_WEBSOCKET_DETAIL_HYBI13_IPP

#include <boost/beast/websocket/detail/hybi13.hpp>
#include <boost/beast/core/detail/sha1.hpp>
#include <boost/beast/websocket/detail/prng.hpp>

#include <boost/assert.hpp>
#include <cstdint>
#include <string>

namespace boost {
namespace beast {
namespace websocket {
namespace detail {

void
make_sec_ws_key(sec_ws_key_type& key)
{
    auto g = make_prng(true);
    char a[16];
    for(int i = 0; i < 16; i += 4)
    {
        auto const v = g();
        a[i  ] =  v        & 0xff;
        a[i+1] = (v >>  8) & 0xff;
        a[i+2] = (v >> 16) & 0xff;
        a[i+3] = (v >> 24) & 0xff;
    }
    key.resize(key.max_size());
    key.resize(beast::detail::base64::encode(
        key.data(), &a[0], 16));
}

void
make_sec_ws_accept(
    sec_ws_accept_type& accept,
    string_view key)
{
    BOOST_ASSERT(key.size() <= sec_ws_key_type::max_size_n);
    static_string<sec_ws_key_type::max_size_n + 36> m(key);
    m.append("258EAFA5-E914-47DA-95CA-C5AB0DC85B11");
    beast::detail::sha1_context ctx;
    beast::detail::init(ctx);
    beast::detail::update(ctx, m.data(), m.size());
    char digest[beast::detail::sha1_context::digest_size];
    beast::detail::finish(ctx, &digest[0]);
    accept.resize(accept.max_size());
    accept.resize(beast::detail::base64::encode(
        accept.data(), &digest[0], sizeof(digest)));
}

} // detail
} // websocket
} // beast
} // boost

#endif // BOOST_BEAST_WEBSOCKET_DETAIL_HYBI13_IPP
