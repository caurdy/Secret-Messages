#ifndef SELF_DESTRUCTING_H
#define SELF_DESTRUCTING_H

#include <string>
using std::string;
#include <vector>
using std::vector;
#include <ios>
using std::ostream; using std::istream;

class SelfDestructingMessage {
  private:
    vector<string> messages_;
    long remaining_views_=0;
    vector<long> views_vec_;
  public:
    SelfDestructingMessage()=default;
    SelfDestructingMessage(vector<string>, long);
    SelfDestructingMessage(SelfDestructingMessage&);
    
    long remaining_views() const {return remaining_views_;};
    vector<string> messages() const {return messages_;};
    vector<long> views_vec() const {return views_vec_;};
    
    int size();
    vector<string> get_redacted();
    long number_of_views_remaining(int index);
    void add_array_of_lines(string [], long);
  
    friend ostream& operator<<(ostream&, const SelfDestructingMessage &);
    friend istream& operator>>(istream&, SelfDestructingMessage &);
    const string& operator[](size_t);
    SelfDestructingMessage& operator=(SelfDestructingMessage);
};
//ostream& operator<<(ostream&, const SelfDestructingMessage &);


#endif