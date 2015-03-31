/*----------------------------------------------------------------
Copyright (c) 2014 Author: Jagadeesh Vasudevamurthy
file: str.cpp

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "str.h"

/*--------------------------------------------------------
static definition - only once at the start
Change to false, if you don't need verbose
----------------------------------------------------------*/
template <typename T>
bool darray<T>::_display = false;

/*----------------------------------------------------------------
Definition of routines of str class
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
Constructor that takes char as argument
-----------------------------------------------------------------*/
str::str(const char ch){
  if (display()) {
    cout << "str::str(const char ch):" << endl;
  }
  int i = 0;
  if (ch != ' ') {
    _str[i++] = ch;
  }
  _str[i] = '\0';
}

/*----------------------------------------------------------------
Constructor that takes char* as argument
-----------------------------------------------------------------*/
str::str(const char* s) :_str(5){
  if (display()) {
    cout << "str::str(const char* s):" << endl;
  }
  int i = 0;
  while (s[i]) {
    _str[i] = s[i];
    i++;
  }
  _str[i] = '\0';
}

/*----------------------------------------------------------------
Destructor
-----------------------------------------------------------------*/
str::~str() {
  if (display()) {
    cout << "str::~str():" << endl;
  }
}

/*----------------------------------------------------------------
Copy Constructor

call copy constructor of darray
Note that  this->_str and s._str is a darray

NOTE that this is possible ONLY with base line initialization.

You cannot write like inside the function:
this->_str(s._str)
-----------------------------------------------------------------*/
str::str(const str& s) :_str(s._str){ //NOTE THIS CALL - IMPT I
  if (display()) {
    cout << "str::str(const str& s):" << endl;
    //error C2064: term does not evaluate to a function taking 1 arguments
    //this->_str(s._str);
  }
}

/*----------------------------------------------------------------
Equal operator
-----------------------------------------------------------------*/
str& str::operator=(const str& rhs) {
  if (display()) {
    cout << "str& str::operator=(const str& rhs) \n";
  }
  /* call equal operator of darray */
  /* Note that this->_str and rhs._str is a darray */
  /* NOte that RELEASE is not required */
  /* RELEASE happens in darray = operator */
  (this->_str) = rhs._str; //NOTE THIS CALL - IMPT II
  return *this;
}


/*----------------------------------------------------------------
s1 == s2 	abc == abc  0
s1 < s2  	abc == abcd 1
s1 > s2 	abcd == abc -1
-----------------------------------------------------------------*/
int string_compare(const str& s1, const str& s2) {
  int i = 0;
  while (s1._str[i] == s2._str[i]) {
    if (s1._str[i] == '\0') {
      return 0; //we come here only s1[i] == s2[i] = '\0'
      // That means they are equal length also
    }
    i++;
  }
  // we come here s1[i] != s2[i]. For smaller s1 or s2 it will be '\0'
  if (s1._str[i] < s2._str[i]) {
    return 1;
  }
  return -1;
}

/*----------------------------------------------------------------
Friend Equal Equal operator
-----------------------------------------------------------------*/
bool operator==(const str& s1, const str& s2) {
  int i = 0;
  while (s1._str[i] == s2._str[i]) {
    if (s1._str[i] == '\0') {
      return true; //we come here only s1[i] == s2[i] = '\0'
      // That means they are equal length also
    }
    i++;
  }
  // we come here s1[i] != s2[i]. For smaller s1 or s2 it will be '\0'
  return false;
}

/*----------------------------------------------------------------
Friend NOT  Equal Equal operator
-----------------------------------------------------------------*/
bool operator!=(const str& s1, const str& s2) {
  return !(s1 == s2);
}

/*----------------------------------------------------------------
strlen
strlen() returns the length of a string, excluding the null
char *j = "jag" ;
strlen = 3;  j[0] = j j[1] = a j[2] = g ; j[3] = '\0' ;
You have allocated 4 spaces. j a g \0
strlen is 3
last character is at 2
-----------------------------------------------------------------*/
int str::strlen() const {
  int i = 0;
  while (_str[i]) {
    i++;
  }
  return i; // '\0 not counted
}

/*----------------------------------------------------------------
reverse
char *j = "jag" ;
strlen = 3;  j[0] = j j[1] = a j[2] = g ; j[3] = '\0' ;

You have allocated 4 spaces. j a g \0
strlen is 3
last character is at 2
-----------------------------------------------------------------*/
void str::reverse() {
  int k = strlen() - 1;//Last character is here
  int i = 0;//First character is here
  while (i < k) {
    char ch = _str[i];
    _str[i] = _str[k];
    _str[k] = ch;
    i++;
    k--;
  }
}

/*----------------------------------------------------------------
print - Friend function
-----------------------------------------------------------------*/
ostream& operator<<(ostream& o, const str& s) {
  int i = 0;
  while (s._str[i] != '\0') {
    o << s._str[i++];
  }
  return o;
}

/*----------------------------------------------------------------
+  Friend function

jag + babu

0123
jag
k will be 3 (number of char in jag = 3. g is at 2)
jagb (we will add b at 3)
-----------------------------------------------------------------*/
str operator+(const str& s1, const str& s2) {
  str ans(s1);
  int k = ans.strlen();
  int i = 0;
  while (s2._str[i]) {
    ans._str[k++] = s2._str[i++];
  }
  ans._str[k] = '\0';
  return ans;
}

#if 0
/*----------------------------------------------------------------
+  Friend function
-----------------------------------------------------------------*/
str operator+(const str& s1, const char s2) {
  str temp(s2);
  return(s1 + temp);
}

/*----------------------------------------------------------------
+  Friend function
-----------------------------------------------------------------*/
str operator+(const char s1, const str& s2) {
  str temp(s1);
  return(temp + s2);
}
#endif

/*----------------------------------------------------------------
Non const string
-----------------------------------------------------------------*/
char& str::operator[](int i) {
  return _str[i]; /* Returned by alias so that user can modify */
}

/*----------------------------------------------------------------
const darray s = "hello" ;
const ch = s[1] ;
-----------------------------------------------------------------*/
const char& str::operator[](int i) const{
  return _str[i];; /* Returned by alias so that user can modify */
}

//EOF


