/*----------------------------------------------------------------
Copyright (c) 2014 Author: Jagadeesh Vasudevamurthy
file: dsorttest.cpp
you require:  ../util/util.cpp ../complex/complex.cpp dsorttest.cpp
On linux:
g++  ../util/util.cpp ../complex/complex.cpp dsorttest.cpp
valgrind a.out
-- All heap blocks were freed -- no leaks are possible
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file test dsort object
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "dsort.h"
#include "../complex/complex.h"

/*--------------------------------------------------------
static definition - only once at the start
Change to false, if you don't need verbose
----------------------------------------------------------*/
template <typename T>
bool dsort<T>::_display = false;

/*--------------------------------------------------------
local to this file. Change verbose = true for debugging
----------------------------------------------------------*/
static bool verbose = true;

/*----------------------------------------------------------------
test complexity
-----------------------------------------------------------------*/
static void test_complexity(const char* t, const int N, int w){
  Random r;
  dsort<int>::set_display(false);
  darray<int> a;
  for (int i = 0; i < N; ++i) {
    int x = r.get_random_number(1000000);
    if (i) {
      a[i] = -x;
    }
    else {
      a[i] = x;
    }
  }
  cout << "--------------------------" << endl;
  cout << t << endl;
  dsort<int> s(a, int_descending_order, N);
  if (w == 0) {
    s.bubble_sort();
  }
  else if (w == 1) {
    s.insertion_sort();
  }
  else if (w == 2) {
    s.merge_sort();
  }
  else if (w == 3) {
    s.quick_sort();
  }
}

/*----------------------------------------------------------------
main
-----------------------------------------------------------------*/
int main() {
  const char* s[] = { "bubble sort", "insertion sort", "merge_sort", "quick sort" };
  int size = sizeof(s) / sizeof(char *);
  for (int i = 0; i < size; ++i) {
    for (int n = 2; n < ((2 << 20) + 1); n = n * 2) {
      test_complexity(s[i], n, i);
    }
  }
  return 0;
}


//EOF

