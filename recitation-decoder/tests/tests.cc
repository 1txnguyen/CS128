#ifndef CATCH_CONFIG_MAIN
#  define CATCH_CONFIG_MAIN
#endif
#include <map>
#include <string>
#include <vector>

#include "catch.hpp"
#include "solution.hpp"

//////////////////////////////////////////////////////////////////////////
// Test Cases
//////////////////////////////////////////////////////////////////////////

TEST_CASE("Basic Replacement", "[prompt]") {
  std::string encoded = "The package has been delivered in the dark";
  std::map<std::string, std::string> mapping = {
      {"package", "target"},
      {"has been delivered", "is secure"},
      {"in the dark", "under cover"}};
  std::string expected = "The target is secure under cover";
  std::string actual = DecodeMessage(encoded, mapping);
  REQUIRE(actual == expected);
}