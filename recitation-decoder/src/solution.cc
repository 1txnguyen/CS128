#include "solution.hpp"

std::string DecodeMessage(const std::string& encoded,
                          const std::map<std::string, std::string>& mapping) {
  std::string result;
  int lens = encoded.length();
  for (int i = 0; i < lens; i++) {
    std::string match;
    std::string lower;
    for (int j = i; j < lens; j++) {
      lower += std::tolower(encoded[j]);
      if (mapping.contains(lower)) {
        match = lower;
      }
    }
    if (match != "") {
      i += match.length() - 1;
      result += mapping.at(match);
    } else {
      result += encoded[i];
    }
  }
  return result;
}
