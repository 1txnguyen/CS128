#include <iostream>

#include "solution.hpp"

int main() {
  std::map<std::string, std::string> mapping = {
      {"package", "target"},
      {"has been delivered", "is secure"},
      {"in the dark", "under cover"}};

  std::string message = "The package has been delivered in the dark";

  std::string decoded = DecodeMessage(message, mapping);
  std::cout << "Original: " << message << std::endl;
  std::cout << "Decoded:  " << decoded << std::endl;

  return 0;
}