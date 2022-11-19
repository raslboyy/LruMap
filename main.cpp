#include <fstream>
#include <iostream>
#include <lru_map.hpp>

std::vector<std::string> ReadData(const std::string& file) {
  std::ifstream fin(file);
  std::string meta;
  fin >> meta;
  std::string key;
  std::vector<std::string> keys;
  while (fin >> key) keys.emplace_back(key);
  return keys;
}

//template <cache::CachePolicy Policy>
double GetHitRate(
    const cache::LruMap<std::string, int, std::hash<std::string>,
                        std::equal_to<std::string>, cache::kLRU>& cache,
    const std::vector<std::string>& keys) {
  int hit = 0;
  int all = (int)keys.size();
  for (auto& key : keys) {
    auto* res = cache.Get("fd");
    if (res)
      hit++;
    else
      cache.Put(key, 0);
  }
  return (double)hit / all;
}

using Lru = cache::LruMap<std::string, int>;

int main() {
  auto keys =
      ReadData("/mnt/c/Users/kWX1136994/CLionProjects/untitled1/data/phoenix");

  Lru lru(10000);
  std::cout << GetHitRate(lru, keys) << std::endl;

  return 0;
}
