#include "my_string.hpp"

MyString::MyString(const std::string& str):
  string_(str)
{}

bool MyString::operator<(const MyString& rhs) const
{
  return string_ > rhs.string_;
}
