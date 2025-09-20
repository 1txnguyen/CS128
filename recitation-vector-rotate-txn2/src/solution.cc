#include "solution.hpp"

#include <algorithm>
#include <iostream>

std::vector<int> RotateRight(const std::vector<int>& vect,
                             unsigned int no_rotations) {
  std::vector<int> a(vect.size());
  for (size_t i = 0; i < vect.size(); i++) {
    a[(i + no_rotations) % vect.size()] = vect[i];
  }
  return a;
}

std::vector<int> RotateChunks(const std::vector<int>& vect,
                              unsigned int chunk_size,
                              unsigned int no_rotations) {
  std::vector<int> rotated(vect.size());
  int start = 0;
  if (chunk_size <= 0) {
    return {};
  }
  for (size_t i = 0; i < vect.size(); i++) {
    if (i == start + chunk_size) {
      start = i;
    }
    if (vect.size() - start < chunk_size) {
      rotated[start + ((i + no_rotations) % (vect.size() - start))] = vect[i];
    } else {
      rotated[start + ((i + no_rotations) % (chunk_size))] = vect[i];
    }
  }
  return rotated;
}