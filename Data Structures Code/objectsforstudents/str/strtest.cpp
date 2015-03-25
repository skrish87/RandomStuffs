/*----------------------------------------------------------------
Copyright (c) 2014 Author: Jagadeesh Vasudevamurthy
file: strtest.cpp

On linux:
g++ str.cpp strtest.cpp
valgrind a.out
-- All heap blocks were freed -- no leaks are possible

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file test str object
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "str.h"

/*--------------------------------------------------------
static definition - only once at the start
Change to false, if you don't need verbose
----------------------------------------------------------*/
bool str::_display = false;

/*--------------------------------------------------------
local to this file. Change verbose = true for debugging
----------------------------------------------------------*/
static bool verbose = true;

/*----------------------------------------------------------------
main
-----------------------------------------------------------------*/
void test1() {
  const char *j = "jag";
  cout << "length of j = " << strlen(j) << endl;
  str s1('U');
  str s2("jag");
  cout << s2 << endl;
  s2.reverse();
  cout << s2 << endl;
  str s3(s2);
  cout << s1 << endl;
  cout << s2 << endl;
  cout << s3 << endl;
  s2 = s1;
  cout << s2 << endl;
  cout << s1 << endl;
  if (s1 == s2) {
    cout << "s1 == s2" << endl;
  }
  if (s1 != s3) {
    cout << "s1 != s3" << endl;
  }
  str s10("abcd");
  str s11("abc");
  int x = string_compare(s10, s11);
  s3 = 'a' + s1;
  cout << "s1 = " << s1 << endl;
  cout << "s3 = " << s3 << endl;
  s3 = s1 + 'p';
  cout << "s3 = " << s3 << endl;
  //s3 = "abc" + "123" ;
  // You cannot do this. At least one in RHS must be str
  s3 = str("abc") + "123";
  cout << "s3 = " << s3 << endl;
  s1 = "++";
  s2 = "Claaaa";
  cout << "Jag " << 'C' + s1 + '+' + '+' + ' ' << s2 << "s" << endl;
}

/*----------------------------------------------------------------
main
-----------------------------------------------------------------*/
int main() {
  str::set_display(verbose);
  test1();
  return 0;
}

//EOF

