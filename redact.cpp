#include "redact.h"
#include<string>
using std::string;
#include<vector>
using std::vector;
#include<iostream>
using std::cout; using std::endl;
//Replaces all non-white space with #
string redact_all_chars(const string & s) {
  string s2 = s;
  for(int i=0; i <= static_cast<int>(s2.length()); ++i) {
    if(s[i] != ' ') {
      s2[i] = '#';
    } else {
      s2[i] = ' ';
    }
  }
  return s2;
}
//Replaces all alphabetic characters or digits with #
string redact_alphabet_digits(const string & s) {
  string s2 = s;
  for(int i=0; i <= static_cast<int>(s2.length()); ++i) {
    if(48 <= s[i] && s[i] <= 57) {
      s2[i] = '#';
    } else if (64 <= s[i] && s[i] <= 90){
      s2[i] = '#';
    } else if  (97 <= s[i] && s[i] <= 122){
      s2[i] = '#';
    } else {
      s2[i] = s[i];
    }
  }
  return s2;
}
//Replaces words in vec_str with # char in string s
string redact_words(const string & s, const vector<string> & vec_str) {
  string s2 = s;
  for(auto str: vec_str) {
    auto str_len = str.length();
    auto pos = s.find(str);
    if(pos < s.length()) {
     s2 = s2.replace(pos,str_len, str_len, '#');
    }
  }
  return s2;
}