#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include <string>
#include <ostream>

struct customer
{
  std::string first_name;
  std::string last_name;
  uint8_t age;

  bool operator!=(customer const &) const;
  friend std::ostream& operator<<(std::ostream &, customer const &);
};

#endif // CUSTOMER_HPP
