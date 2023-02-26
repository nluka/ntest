#ifndef CUSTOM_EXCEPTION_HPP
#define CUSTOM_EXCEPTION_HPP

#include <exception>

struct custom_exception : public std::exception
{
  [[nodiscard]] virtual char const *what() const noexcept
  {
    return "Something bad happened";
  }
};

#endif // CUSTOM_EXCEPTION_HPP
