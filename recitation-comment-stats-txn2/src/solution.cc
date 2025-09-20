#include "solution.hpp"

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

CommentStats GenerateCommentStats(const std::vector<std::string>& comments) {
  std::set<char> punct = {'!', '?', ',', '.', '\'', ' '};
  std::map<std::string, int> users;
  for (std::string c : comments) {
    std::string track;
    int r = c.size();
    for (int i = 0; i < r; i++) {
      char d = std::tolower(c[i]);
      if (d == '@') {
        if (track.size() > 1) {
          if (users.contains(track)) {
            users[track] += 1;
          } else {
            users[track] = 1;
          }
        }
        track = "@";
      } else if (track.size() == 1 && punct.contains(d)) {
        track = "";
      } else if (track.size() > 1 && punct.contains(d)) {
        if (users.contains(track)) {
          users[track] += 1;
        } else {
          users[track] = 1;
        }
        track = "";
      } else if (track.size() >= 1 && track[0] == '@') {
        track.push_back(d);
      }
    }
    if (track.size() > 1) {
      if (users.contains(track)) {
        users[track] += 1;
      } else {
        users[track] = 1;
      }
    }
  }
  std::vector<std::string> popularity;
  for (const auto& pair : users) {
    if (pair.second >= 2) {
      popularity.push_back(pair.first);
    }
  }
  struct CommentStats result = {users, popularity};
  return result;
}