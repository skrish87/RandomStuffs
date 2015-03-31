/*----------------------------------------------------------------
Copyright (c) 2014 Author: Jagadeesh Vasudevamurthy
file: ulongnum.cpp

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "ulongnum.h"
/*----------------------------------------------------------------

Definition of routines of ulongnum class
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
Constructor that takes char as argument
-----------------------------------------------------------------*/
ulongnum::ulongnum(const char ch) :_ulongnum(ch){
  if (display()) {
    cout << "ulongnum::ulongnum(const const ch):" << endl;
  }
}

/*----------------------------------------------------------------
Constructor that takes char* as argument
-----------------------------------------------------------------*/
ulongnum::ulongnum(const char* s) :_ulongnum(s){
  if (display()) {
    cout << "ulongnum::ulongnum(const char* s):" << endl;
  }
}

/*----------------------------------------------------------------
Build object from unsigned number
-----------------------------------------------------------------*/
void ulongnum::_build(const unsigned s1){
  unsigned s = s1;
  unsigned i = 0;
  while (s) {
    _ulongnum[i++] = (s % 10) + '0';
    s = s / 10;
  }
  _ulongnum[i] = '\0';
  _ulongnum.reverse();
}

/*----------------------------------------------------------------
Constructor that takes unsigned as argument
-----------------------------------------------------------------*/
ulongnum::ulongnum(const unsigned s1){
  if (display()) {
    cout << "ulongnum::ulongnum(const unsigned s):" << endl;
  }
  _build(s1);
}

/*----------------------------------------------------------------
Constructor that takes int
-----------------------------------------------------------------*/
ulongnum::ulongnum(const int t){
  assert(t >= 0);
  unsigned s1 = unsigned(t);
  _build(s1);
}

/*----------------------------------------------------------------
Constructor that takes str as argument
-----------------------------------------------------------------*/
ulongnum::ulongnum(const str s) :_ulongnum(s){
  if (display()) {
    cout << "ulongnum::ulongnum(const str s):" << endl;
  }
}

/*----------------------------------------------------------------
Destructor
-----------------------------------------------------------------*/
ulongnum::~ulongnum() {
  if (display()) {
    cout << "ulongnum::~ulongnum():" << endl;
  }
}

/*----------------------------------------------------------------
Copy Constructor
-----------------------------------------------------------------*/
ulongnum::ulongnum(const ulongnum& s) :_ulongnum(s._ulongnum){
  if (display()) {
    cout << "ulongnum::ulongnum(const ulongnum& s):" << endl;
  }
}

/*----------------------------------------------------------------
Equal operator
-----------------------------------------------------------------*/
ulongnum& ulongnum::operator=(const ulongnum& rhs) {
  if (display()) {
    cout << " ulongnum& ulongnum::operator=(const ulongnum& rhs:\n";
  }
  this->_ulongnum = rhs._ulongnum;
  return *this;
}

/*----------------------------------------------------------------
Friend Equal Equal operator
-----------------------------------------------------------------*/
bool operator==(const ulongnum& s1, const ulongnum& s2) {
  return(s1._ulongnum == s2._ulongnum);
}

/*----------------------------------------------------------------
Friend NOT  Equal Equal operator
-----------------------------------------------------------------*/
bool operator!=(const ulongnum& s1, const ulongnum& s2) {
  return (!(s1 == s2));
}


/*----------------------------------------------------------------
numdigit
245 -> returns as 3
-----------------------------------------------------------------*/
int ulongnum::numdigit() const {
  return _ulongnum.strlen();
}

/*----------------------------------------------------------------
reverse
-----------------------------------------------------------------*/
void ulongnum::reverse() {
  _ulongnum.reverse();
}

/*----------------------------------------------------------------

-----------------------------------------------------------------*/
ostream& operator<<(ostream& o, const ulongnum& s) {
  unsigned k = 0;
  unsigned i = 0;
  char ch;
  while (ch = s._ulongnum[i++]) {
    if (++k > 30) {
      o << endl;
      k = 0;
    }
    o << ch;
  }
  return o;
}

/*----------------------------------------------------------------
+  Friend function
add two numbers
236         0 z
8           6 x
---         8 y
244
-----------------------------------------------------------------*/
ulongnum operator+(const ulongnum& s1, const ulongnum& s2) {
  int l1 = s1.strlen() - 1; //last digit here
  int l2 = s2.strlen() - 1; //last digit here
  int max = l1;
  if (l2 > max) {
    max = l2;
  }
  str l;
  int z = 0;
  int k = 0;
  for (int i = max; i >= 0; i--) {
    int x = 0;
    if (l1 >= 0) {
      char  ch = s1[l1--];
      x = ch - '0';
    }
    int y = 0;
    if (l2 >= 0) {
      char ch = unsigned(s2[l2--]);
      y = ch - '0';
    }
    int t = x + y + z;
    assert(t >= 0 && t <= 19);
    if (t < 10) {
      l[k++] = t + '0';
      z = 0;
    }
    else {
      l[k++] = (t - 10) + '0';
      z = 1;
    }
  }
  if (z == 1) {
    l[k++] = '1';
  }
  l[k++] = '\0';
  l.reverse();
  return l;
}

/*----------------------------------------------------------------
Multiplication
-----------------------------------------------------------------*/
ulongnum operator*(const ulongnum& s1, const ulongnum& s2) {
  ulongnum ans(0);
  const ulongnum* p1 = &s1;
  const ulongnum* p2 = &s2;

  // ans = s1 * s2
  // Make sure s2 is smaller than s1
  // distinguish  5678 * 82  or 82 * 5678 
  if (s2.numdigit() > s1.numdigit()) {
    p1 = &s2;
    p2 = &s1;
  }
  //5678 * 82
  int itr = -1;
  for (int i = (*p2).numdigit() - 1; i >= 0; i--) {
    itr++;
    int y = (*p2)[i] - '0';
    ulongnum pp(0);
    int pos = 0;
    for (int k = 0; k < itr; k++) {
      pp[pos++] = '0';
    }
    int r = 0;
    for (int j = (*p1).numdigit() - 1; j >= 0; j--) {
      int x = ((*p1)[j] - '0');
      int p = x * y;
      int s = p + r;
      pp[pos++] = (s % 10) + '0';
      r = s / 10;
      if (j == 0 && r) {
        assert(r < 10);
        pp[pos++] = r + '0';
      }
    }
    pp[pos] = '\0';
    pp.reverse();
    ans = ans + pp;
  }
  return ans;
}

/*----------------------------------------------------------------
!5 = 5 * 4 * 3 * 2 * 1
-----------------------------------------------------------------*/
void ulongnum::factorial(unsigned n) {
  ulongnum one(1);
  *this = one;
  for (unsigned i = 2; i <= n; i++) {
    *this = *this * i;
  }
}


//EOF


