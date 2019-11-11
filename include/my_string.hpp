#ifndef MY_STRING_HPP
#define MY_STRING_HPP

#include <string>

class MyString {
public:
  std::string string_;
  MyString(const std::string& str);
  bool operator<(const MyString& rhs) const;
};

#endif //!MY_STRING_HPP
