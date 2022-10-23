#include "customer.hpp"

bool customer::operator!=(customer const &other) const
{
  return this->first_name != other.first_name
    || this->last_name != other.last_name
    || this->age != other.age;
}

std::ostream& operator<<(std::ostream &os, customer const &cust)
{
  os
    << '(' << cust.first_name << ' ' << cust.last_name
    << ", " << (int)cust.age << ')';
  return os;
}
