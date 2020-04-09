/*----------------------------------------------------------------
Copyright (c) 2014 Author: Jagadeesh Vasudevamurthy
file: ulongnum.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has ulongnum class declaration
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#ifndef ulongnum_H
#define ulongnum_H

#include "../str/str.h"

/*--------------------------------------------------------
class ulongnum
----------------------------------------------------------*/
class ulongnum {
public:
  ulongnum(const char *s);
  ulongnum(const char ch);
  ulongnum(const unsigned i);
  ulongnum(const int i=0);
  ulongnum(const str s);
  ~ulongnum();
  ulongnum(const ulongnum& s);
  ulongnum& operator=(const ulongnum& rhs);

  //Basic
  int strlen() const{ return _ulongnum.strlen(); }
  int numdigit() const;
  bool display() const { return _display; }
  void reverse();

  //unary operation
  friend ulongnum operator+(const ulongnum& a);
  friend ulongnum  operator-(const ulongnum& a);

  //increment and decrement
  friend ulongnum& operator++(ulongnum& a);
  friend ulongnum  operator++(ulongnum& a, int i);
  friend ulongnum& operator--(ulongnum& a);
  friend ulongnum  operator--(ulongnum& a, int i);

  // cout
  friend ostream& operator<<(ostream& o, const ulongnum& s);

  // Access
  char& operator[](unsigned i) { return _ulongnum[i]; } //For non constant objects
  const char& operator[](unsigned i) const  { return _ulongnum[i]; }; //for constant objects

  // Comparator 
  friend bool operator==(const ulongnum& s1, const ulongnum& s2);
  friend bool operator!=(const ulongnum& s1, const ulongnum& s2);
  friend bool operator<=(const ulongnum& a, const ulongnum& b);
  friend bool operator>=(const ulongnum& a, const ulongnum& b);

  //addition and subtraction
  friend  ulongnum operator+(const ulongnum& s1, const ulongnum& s2);
  friend  ulongnum operator-(const ulongnum& s1, const ulongnum& s2);

  /* += and  -= operator */
  friend ulongnum& operator+=(ulongnum& a, const ulongnum& b);
  friend ulongnum& operator-=(ulongnum& a, const ulongnum& b);

  //multiplication
  friend  ulongnum operator*(const ulongnum& s1, const ulongnum& s2);

  //factorial. 
  // friendand templates on linux has a bug
  //friend ulongnum factorial(unsigned n);
  void  factorial(unsigned n);

  static void set_display(bool x) {
    str::set_display(x);
    _display = x;
  }

private:
  str _ulongnum;
  static bool _display; /* ONLY ONCE for all object */
  void _build(const unsigned s1);
};

#endif
//EOF

