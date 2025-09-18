#include "solution.hpp"

Student ReadStudentRecFromStream(std::istream& is) {
  Student result;
  std::string file_headers;
  // std::getline(is, file_headers);
  std::string first = "";
  std::string last = "";
  unsigned int uin = 0;
  double gpa = 0.0;
  char throws = ',';
  is >> first >> last >> uin >> throws >> gpa;
  if (is.fail()) {
    return result;
  }
  if (last[last.length() - 1] != ',' || throws != ',') {
    return result;
  }
  std::string name = first;
  name += " ";
  name += last;

  name.pop_back();
  result = {name, uin, gpa};
  return result;
}