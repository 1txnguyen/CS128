#include <fstream>
#include <iostream>

#include "solution.hpp"

int main() {
  // bind std::ifstream to file...
  std::ifstream ifs("./data/input.csv");

  // testing your implementation...
  while (ifs.good()) {
    Student student = ReadStudentRecFromStream(ifs);
    if (ifs.fail()) break;
    std::cout << student.full_name << '\t' << student.uin << '\t' << student.gpa
              << '\n';
  }
}