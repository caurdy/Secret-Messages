#include "self_destructing.h"
#include "redact.h"
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <iostream>
using std::ostream;
using std::endl; using std::cout;
/*
void swap(SelfDestructingMessage& sdm1, SelfDestructingMessage& sdm2) {
  sdm1.messages().swap(sdm2.messages());
  std::swap(sdm1.remaining_views() , sdm2.remaining_views());
  sdm1.views_vec().swap(sdm2.views_vec());
}
*/
SelfDestructingMessage::SelfDestructingMessage(SelfDestructingMessage &sdm){
  //SelfDestructingMessage sdm_blank;
  //copy value to LHS
  messages_ = sdm.messages();
  remaining_views_ = sdm.remaining_views();
  views_vec_ = sdm.views_vec();
  //zero out RHS values
  sdm.messages_ = {};
  sdm.remaining_views_ = 0;
  sdm.views_vec_ = {};
}
SelfDestructingMessage& SelfDestructingMessage::operator=(SelfDestructingMessage
                                                                         sdm) {
  //transfer RHS to LHS
  messages_ = sdm.messages();
  remaining_views_ = sdm.remaining_views();
  views_vec_ = sdm.views_vec();
  //Zero out RHS
  sdm.messages_ = {};
  sdm.remaining_views_ = 0;
  sdm.views_vec_ = {};
  
  return *this;
}
SelfDestructingMessage::SelfDestructingMessage(vector<string> messages, 
                                                          long views) {
  messages_ = messages;
  remaining_views_ = views;
  for(auto m: messages) {
    views_vec_.push_back(views);
  }
}
ostream& operator<<(ostream& out, const SelfDestructingMessage & sdm) {
  int cnt=0;
  for(auto m: sdm.messages()) {
    out << std::to_string(sdm.views_vec_[cnt]);
    out << ":";
    out << m;
    cnt += 1;
  }
  return out;
}
int SelfDestructingMessage::size() {
  int cnt = 0;
  for(auto m : messages_) {
    cnt += 1;
  }
  return cnt;
}
vector<string> SelfDestructingMessage::get_redacted() {
  vector<string> messages_vec;
  for(auto m : messages_) {
    messages_vec.push_back(redact_alphabet_digits(m));
  }
  return messages_vec;
}
long SelfDestructingMessage::number_of_views_remaining(int index) {
  return views_vec_[index];
}
const string & SelfDestructingMessage::operator[](size_t index){
  views_vec_[index] -= 1;
  return messages_[index];
}
void SelfDestructingMessage::add_array_of_lines(string ary [], long size) {
  
}
