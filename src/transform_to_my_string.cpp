#include "transform_to_my_string.hpp"

MyString transform_to_my_string::operator()(const std::string& str) const
{
  return MyString(str);
}
