#include "functions.hpp"

#include <iostream>
#include <map>
#include <set>
#include <stdexcept>
#include <vector>

/**
 * TODO: Implement this function
 * @param word word to change to lowercase
 * @return result of changing every character in word to lowercase
 */
std::string StringToLower(const std::string& word) {
  std::string w;
  for (char c : word) {
    w.push_back(std::tolower(c));
  }
  std::cout << "Input to StringToLower() : " << word << std::endl;
  return w;
}

/**
 * TODO: Implement this function
 * @param v1 first character in potential vowel group
 * @param v2 second character in potential vowel group
 * @return true if v1 and v2 form a valid vowel group
 */
bool IsVowelGroup(const char& v1, const char& v2) {
  std::cout << "Input to IsVowelGroup() : \"" << v1 << "\" \"" << v2 << "\""
            << std::endl;
  std::set<std::string> c = {
      "ai", "ae", "ao", "au", "ei", "eu", "iu", "oi", "ou", "ui"};
  std::string d;
  d.push_back(v1);
  d.push_back(v2);
  bool cond = false;
  if (c.contains(d)) {
    cond = true;
  }
  return cond;
}

/**
 * TODO: Complete this function
 * @param v potential vowel character
 * @return true if v is a vowel
 */
bool IsVowel(const char& v) {
  std::cout << "Input to IsVowel() : \"" << v << "\"" << std::endl;
  std::set<char> c = {'a', 'e', 'i', 'o', 'u'};
  bool cond = false;
  if (c.contains(v)) {
    cond = true;
  }
  return cond;
}

/**
 * TODO: Complete this function
 * @param c potential consonant character
 * @return true if c is a consonant
 */
bool IsConsonant(const char& c) {
  std::cout << "Input to IsConsonant() : \"" << c << "\"" << std::endl;
  std::set<char> r = {'p', 'k', 'h', 'l', 'm', 'n', 'w'};
  bool cond = false;
  if (r.contains(c)) {
    cond = true;
  }
  return cond;
}

/**
 * TODO: Implement this function
 * @param c character to check validity of
 * @return true if input c is a valid character in the Hawaiian language, false
 * otherwise
 */
bool IsValidCharacter(const char& c) {
  std::cout << "Input to IsValidCharacter() : \"" << c << "\"" << std::endl;
  std::set<char> r = {
      'p', 'k', 'h', 'l', 'm', 'n', 'w', 'a', 'e', 'i', 'o', 'u', ' ', '\''};
  bool cond = false;
  if (r.contains(c)) {
    cond = true;
  }
  return cond;
}

/**
 * TODO: Implement this function
 * @param word word to check validity of
 * @return true if every character in word is a valid character in the Hawaiian
 * language, false otherwise
 */
bool IsValidWord(const std::string& word) {
  std::cout << "Input to IsValidWord() : " << word << std::endl;
  std::set<char> apost = {' ', '\''};
  bool cond = true;
  for (char d : word) {
    if (!IsValidCharacter(d) && !apost.contains(d)) {
      cond = false;
      break;
    }
  }
  return cond;
}

/**
 * TODO: Implement this function
 * @param c consonant to get pronunciation of
 * @param prev character before c, used for determining w translation
 *    set to null character as default if no value is passed in
 * @return pronunciation of the consonant c as a char
 */
char ConsonantPronunciation(const char& c, const char& prev) {
  std::cout << "Input to ConsonantPronunciation() : \"" << c << "\" \"" << prev
            << "\"" << std::endl;
  std::set<char> norm = {'p', 'k', 'h', 'l', 'm', 'n'};
  if (norm.contains(c)) {
    return c;
  }
  if (c == 'w') {
    if (prev == 'i' || prev == 'e') {
      return 'v';
    } else if (prev == 'o' || prev == 'u') {
      return 'w';
    }
  }
  return 'w';
}

/**
 * TODO: Implement this function
 * @param v1 first vowel in a vowel grouping
 * @param v2 second vowel in a vowel grouping
 * @return the pronunciation of the vowel grouping made up of v1 and v2
 * as a string
 */
std::string VowelGroupPronunciation(const char& v1, const char& v2) {
  std::cout << "Input to VowelGroupPronunciation() : \"" << v1 << "\" \"" << v2
            << "\"" << std::endl;
  std::map<std::string, std::string> vow = {{"ai", "eye"},
                                            {"ae", "eye"},
                                            {"ao", "ow"},
                                            {"au", "ow"},
                                            {"ei", "ay"},
                                            {"eu", "eh-oo"},
                                            {"iu", "ew"},
                                            {"oi", "oy"},
                                            {"ou", "ow"},
                                            {"ui", "ooey"}};
  std::string d;
  d.push_back(v1);
  d.push_back(v2);
  return vow[d];
}

/**
 * TODO: Implement this function
 * @param v single vowel to get pronunciation of
 * @return the pronunciation of v as a string
 */
std::string SingleVowelPronunciation(const char& v) {
  std::cout << "Input to SingleVowelPronunciation() : \"" << v << "\""
            << std::endl;
  std::map<std::string, std::string> vow = {
      {"a", "ah"}, {"e", "eh"}, {"i", "ee"}, {"o", "oh"}, {"u", "oo"}};
  std::string d;
  d.push_back(v);
  return vow[d];
}

/**
 * TODO: Implement this function
 * @param prev first character in set of three passed to function
 * @param curr second character in set of three passed to function
 * @param next third character in set of three passed to function
 * @return pronunciation of curr using next and prev as needed to determine
 * result
 */
std::string ProcessCharacter(const char& prev,
                             const char& curr,
                             const char& next) {
  std::cout << "Input to ProcessCharacter() : \"" << prev << "\" \"" << curr
            << "\" \"" << next << "\"" << std::endl;
  std::string r;
  if (curr == '\'' || curr == ' ') {
    r.push_back(curr);
    return r;
  }
  if (IsVowelGroup(curr, next) && next != ' ') {
    r = VowelGroupPronunciation(curr, next);
  } else if (IsVowel(curr)) {
    r = SingleVowelPronunciation(curr);
  } else if (IsConsonant(curr)) {
    char d = ConsonantPronunciation(curr, prev);
    std::string c;
    c.push_back(d);
    r = c;
  }
  return r;
}

/**
 * TODO: Implement this function
 * @param word string to get pronunciation of
 * @return pronunciation of word
 */
std::string Pronunciation(const std::string& word) {
  std::cout << "Input to Pronunciation() : " << word << std::endl;
  std::string result;
  std::set<char> g = {' ', '\''};
  int lens = word.length();
  int iterator = 0;
  while (iterator < lens) {
    if (g.contains(word[iterator])) {
      result += word[iterator];
      iterator += 1;
      continue;
    } else {
      char prev = (iterator == 0 ? ' ' : word[iterator - 1]);
      char curr = word[iterator];
      char next = (iterator == lens - 1 ? ' ' : word[iterator + 1]);
      std::string d = ProcessCharacter(prev, curr, next);
      if (IsVowelGroup(curr, next)) {
        iterator += 2;
      } else {
        iterator += 1;
      }
      if (IsVowel(prev) && (IsConsonant(curr) || IsVowel(curr))) {
        result += "-";
      }
      result += d;
    }
  }
  if (result.back() == '-') {
    result.pop_back();
  }
  return result;
}

/**
 * TODO: Implement this function
 * @param hawaiian_word word to get pronunciation of
 * @return the pronunciation of hawaiian_word as a string if valid
 *  and throws an invalid_argument error if not valid
 */
std::string GetPronunciation(const std::string& hawaiian_word) {
  std::cout << "Input to GetPronunciation() : " << hawaiian_word << std::endl;
  std::string news = StringToLower(hawaiian_word);
  if (!IsValidWord(news)) {
    throw std::invalid_argument("Description of Problem");
  }
  return Pronunciation(news);
}