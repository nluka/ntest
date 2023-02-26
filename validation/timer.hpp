#ifndef NLUKA_TIMER_HPP
#define NLUKA_TIMER_HPP

#include <chrono>
#include <ostream>
#include <string_view>

namespace timer {

enum class unit {
  SECONDS      = 1,
  MILLISECONDS = 1'000,
  MICROSECONDS = 1'000'000,
  NANOSECONDS  = 1'000'000'000,
};

// A scope-based timer.
template <unit UnitTy>
class scoped {
public:
  scoped(char const *const label, std::ostream &os)
  : m_label{label},
    m_os{os},
    m_start{std::chrono::steady_clock::now()}
  {}

  // copy constructor
  scoped(scoped const &) = delete;

  // copy assignment
  scoped &operator=(scoped const &) = delete;

  // move constructor
  scoped(scoped &&) noexcept = delete;

  // move assignment
  scoped &operator=(scoped &&) noexcept = delete;

  ~scoped() {
    using timer::unit;

    auto const end = std::chrono::steady_clock::now();

    auto const elapsedNanos = end - m_start;

    auto const elapsedTimeInTemplatedUnits =
      static_cast<double>(elapsedNanos.count()) /
      static_cast<double>([]() {
        switch (UnitTy) {
          default:
          case unit::SECONDS:      return unit::NANOSECONDS;
          case unit::MILLISECONDS: return unit::MICROSECONDS;
          case unit::MICROSECONDS: return unit::MILLISECONDS;
          case unit::NANOSECONDS:  return unit::SECONDS;
        }
      }());

    char const *const units = []() {
      switch (UnitTy) {
        default:
        case unit::SECONDS:      return "s";
        case unit::MILLISECONDS: return "ms";
        case unit::MICROSECONDS: return "us";
        case unit::NANOSECONDS:  return "ns";
      }
    }();

    m_os << m_label << " took " << elapsedTimeInTemplatedUnits << units << '\n';
  }

private:
  std::string_view const m_label;
  std::ostream &m_os;
  std::chrono::time_point<std::chrono::steady_clock> const m_start;
};

} // namespace timer

#endif // NLUKA_TIMER_HPP
