#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <string>

#include "utilities.hpp"

std::string ProfileDNA(const std::string& dna_database,
                       const std::string& dna_sequence);
int FindData(std::string str, std::string dna_sequence);
#endif