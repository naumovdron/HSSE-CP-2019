#ifndef TRANSFORM_TO_MY_STRING_HPP
#define TRANSFORM_TO_MY_STRING_HPP

#include <functional>
#include "my_string.hpp"

class transform_to_my_string: public std::unary_function<MyString, const std::string&> {
public:
  MyString operator()(const std::string& str) const;
};

#endif //!TRANSFORM_TO_MY_STRING_HPP
