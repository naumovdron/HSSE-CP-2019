#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include "transform_to_my_string.hpp"

std::ostream& operator<<(std::ostream& out, const MyString& myStr)
{
  return out << myStr.string_;
}

int main(int, char**) {
  std::vector<std::string> strings;
  std::copy(std::istream_iterator<std::string>(std::cin), std::istream_iterator<std::string>(), std::back_inserter(strings));

  std::vector<MyString> myStrings;
  std::transform(strings.begin(), strings.end(), std::back_inserter(myStrings), transform_to_my_string());
  std::sort(myStrings.begin(), myStrings.end());

  std::copy(myStrings.begin(), myStrings.end(), std::ostream_iterator<MyString>(std::cout, "\n"));
  return 0;
}
