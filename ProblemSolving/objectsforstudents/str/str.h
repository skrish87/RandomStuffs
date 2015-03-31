/*----------------------------------------------------------------
Copyright (c) 2014 Author: Jagadeesh Vasudevamurthy
file: str.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has str class declaration
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#ifndef str_H
#define str_H

#include "../darray/darray.h"

/*----------------------------------------------------------------
Declaration of str class
-----------------------------------------------------------------*/
class str {
public:
  str(const char* s);
  str(const char ch = ' ');
  ~str();
  str(const str& s);
  str& operator=(const str& rhs);
  friend bool operator==(const str& s1, const str& s2);
  friend bool operator!=(const str& s1, const str& s2);
  friend int string_compare(const str& s1, const str& s2);
  friend ostream& operator<<(ostream& o, const str& s);
  int strlen() const;
  void reverse();
  friend  str operator+(const str& s1, const str& s2);
  char& operator[](int i); //For non constant object
  const char& operator[](int i) const; //for constant objects
  bool display() const { return _display; }
  static void set_display(bool x) {
    darray<char>::set_display(x);
    _display = x;
  }
private:
  darray<char> _str;
  static bool _display; /* ONLY ONCE for all object */
};

bool str::_display = true;
#endif
//EOF

