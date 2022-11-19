#pragma once

namespace cache {
    enum CachePolicy {
        kLRU = 0, kSLRU, kLFU, kTinyLFU, kWTinyLFU
    };
    enum FrequencySketchPolicy {
        Trivial = 0, Bloom, DoorkeeperBloom
    };
}  // namespace cache
