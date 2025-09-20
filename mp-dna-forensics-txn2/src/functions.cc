#include "functions.hpp"

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

std::string ProfileDNA(const std::string& dna_database,
                       const std::string& dna_sequence) {
  // std::cout << "Input dna_database : " << dna_database << std::endl;
  // std::cout << "Input dna_sequence : " << dna_sequence << std::endl;

  // write your implementation here... we strongly encourage that you leverage
  // additional functions to define this behavior.

  std::vector<std::vector<std::string>> results;
  std::ifstream ifs{dna_database};
  for (std::string line; std::getline(ifs, line); line = "") {
    results.push_back(utilities::GetSubstrs(line, ','));
  }
  std::string stri;
  std::vector<int> counts;
  int size = static_cast<int>(results.size());
  int r = static_cast<int>(results[0].size());
  for (int j = 1; j < r; j++) {
    counts.push_back(FindData(results[0][j], dna_sequence));
  }

  for (int i = 1; i < size; i++) {
    std::vector<int> current;
    for (int j = 1; j < r; j++) {
      current.push_back(std::stoi(results[i][j]));
    }
    if (current == counts) {
      if (!stri.empty()) {
        return "No match";
      }
      stri = results[i][0];
    }
  }
  if (!stri.empty()) {
    return stri;
  }
  return "No match";
}
int FindData(std::string str, std::string dna) {
  int result = 0;
  int len = static_cast<int>(str.length());
  int dna_len = static_cast<int>(dna.length());
  for (int i = 0; i < dna_len; ++i) {
    int current = 0;
    while (i + len <= dna_len && dna.substr(i, len) == str) {
      current++;
      i += len;
    }
    if (current > result) {
      result = current;
    }
  }
  std::cout << result << str;
  return result;
}