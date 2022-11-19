#pragma once

#include <functional>
#include <typeindex>
#include "policy.hpp"

namespace cache::impl {
    template<typename T, typename U, typename Hash = std::hash<T>,
            typename Equal = std::equal_to<T>,
            CachePolicy Policy = CachePolicy::kLRU,
            CachePolicy...>
    class LruBase final {
    };
}  // namespace cache::impl
