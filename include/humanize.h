

#ifndef HUMANIZE_HUMANIZE_H
#define HUMANIZE_HUMANIZE_H

#include <chrono>
#include <sstream>
#include <iomanip>
#include <fstream>

namespace humanize {
  template <class _Rep, class _Period>
  std::string duration(const std::chrono::duration<_Rep, _Period>& d) {
    std::chrono::duration<_Rep, _Period> d2(d);
    return duration(std::move(d2));
  }
  template <class _Rep, class _Period>
  std::string duration(std::chrono::duration<_Rep, _Period>&& d) {
    using namespace std::literals;
    std::ostringstream oss;
    oss << std::setprecision(3);
    if (d > 0.1s) {
      oss << d * 1.0 / 1s << "s";
    } else if (d > 0.1ms) {
      oss << d * 1.0 / 1ms << "ms";
    } else {
      oss << d * 1.0 / 1ms * 1000 << "µs";
    }
    return oss.str();
  }

  const size_t KB = 1024;
  const size_t MB = 1024 * KB;
  const size_t GB = 1024 * MB;
  const size_t TB = 1024 * GB;

  std::string bytes(size_t b) {
    std::ostringstream oss;
    oss << std::setprecision(3);
    if (b > TB || b * 10 > TB) {
      oss << double(b) / TB << "TiB";
    } else if (b > GB || b * 10 > GB) {
      oss << double(b) / GB << "GiB";
    } else if (b > MB || b * 10 > MB) {
      oss << double(b) / MB << "MiB";
    } else if (b > KB || b * 10 > KB) {
      oss << double(b) / KB << "KiB";
    } else {
      oss << b << "B";
    }
    return oss.str();
  }
}

#endif //HUMANIZE_HUMANIZE_H
