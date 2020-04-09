/*----------------------------------------------------------------
Copyright (c) 2014 Author: Jagadeesh Vasudevamurthy
file: recursiontest.cpp

On linux:
g++ ../str/str.cpp recursion.cpp recursiontest.cpp
valgrind a.out
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file test recursion object 
NOTHING CAN BE CHANGED BELOW
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "recursion.h"

/*----------------------------------------------------------------
test factorial
-----------------------------------------------------------------*/
void test_factorial() {
  recursion f;
  cout << "-----------------------Factorial using iteration-----------------------\n";
  for (int i = 0; i < 30; ++i) {
    int num_mult = 0;
    long long a = f.factorial_iterative(i, num_mult);
    cout << "factorial_iterative: f(" << i << ")= " << a << " Number of mult = " << num_mult << endl;
  }
  cout << "-----------------------Factorial using recursion-----------------------\n";
  for (int i = 0; i < 30; ++i) {
    int num_rec = 0;
    long long a = f.factorial_recursion(i, num_rec);
    cout << "factorial_recursion: f(" << i << ")= " << a << " Number of recursion = " << num_rec << endl;
  }
  cout << "-----------------------Factorial using stack-----------------------\n";
  for (int i = 0; i < 30; ++i) {
    int size_of_stack = 0;
    long long a = f.factorial_stack(i, size_of_stack);
    cout << "factorial_stack: f(" << i << ")= " << a << " Size of stack = " << size_of_stack << endl;
    int num_mult = 0;
    assert(a == f.factorial_iterative(i, num_mult));
  }
}

/*----------------------------------------------------------------
test factorial
-----------------------------------------------------------------*/
void test_num_binary_digit() {
  recursion f;
  cout << "-----------------------num_binary_digits using iteration-----------------------\n";
  for (int i = 0; i < 30; ++i) {
    int num_itr = 0;
    int a = f.num_binary_digit_iterative(i, num_itr);
    cout << "num_binary_digits_iterative: f(" << i << ")= " << a << " Number of itr = " << num_itr << endl;
  }
  cout << "-----------------------num_binary_digits using recursion-----------------------\n";
  for (int i = 0; i < 30; ++i) {
    int num_rec = 0;
    int a = f.num_binary_digit_recursion(i, num_rec);
    cout << "num_binary_digits_recursion: f(" << i << ")= " << a << " Number of recursion = " << num_rec << endl;
  }
  cout << "-----------------------num_binary_digits_using stack-----------------------\n";
  for (int i = 0; i < 30; ++i) {
    int size_of_stack = 0;
    int a = f.num_binary_digit_stack(i, size_of_stack);
    cout << "num_binary_digits_stack: f(" << i << ")= " << a << " Size of stack = " << size_of_stack << endl;
    int num_itr = 0;
    assert(a == f.num_binary_digit_iterative(i, num_itr));
  }
  cout << "-----------------------num_binary_digits_using stack TEST FOR 300000-----------------------\n";
  for (int i = 0; i < 300000; ++i) {
    int size_of_stack = 0;
    int a = f.num_binary_digit_stack(i, size_of_stack);
    if (i % 10000 == 0) {
      cout << "num_binary_digits_stack: f(" << i << ")= " << a << " Size of stack = " << size_of_stack << endl;
    }
    int num_itr = 0;
    assert(a == f.num_binary_digit_iterative(i, num_itr));
    assert(a == f.num_binary_digit_recursion(i, num_itr));
  }
}

/*----------------------------------------------------------------
test fibonacci
-----------------------------------------------------------------*/
void test_fibonacci() {
  recursion f;
  cout << "-----------------------fibonacci using iteration-----------------------\n";
  for (int i = 0; i < 30; ++i) {
    int num_itr = 0;
    int a = f.fibonacci_iterative(i, num_itr);
    cout << "fibonacci_iterative: f(" << i << ")= " << a << " Number of itr = " << num_itr << endl;
  }
  cout << "-----------------------fibonacci using recursion-----------------------\n";
  for (int i = 0; i < 30; ++i) {
    int num_rec = 0;
    int a = f.fibonacci_recursion(i, num_rec);
    cout << "fibonacci_recursion: f(" << i << ")= " << a << " Number of recursion = " << num_rec << endl;
  }
  cout << "-----------------------fibonacci_using stack-----------------------\n";
  for (int i = 0; i < 30; ++i) {
    int size_of_stack = 0;
    int a = f.fibonacci_stack(i, size_of_stack);
    cout << "fibonacci_stack: f(" << i << ")= " << a << " Size of stack = " << size_of_stack << endl;
    int num_itr = 0;
    assert(a == f.fibonacci_iterative(i, num_itr));
  }
  cout << "-----------------------num_binary_digits_using stack TEST FOR 300000-----------------------\n";
  for (int i = 0; i < 35; ++i) {
    int size_of_stack = 0;
    int a = f.fibonacci_stack(i, size_of_stack);
    cout << "fibonacci_stack: f(" << i << ")= " << a << " Size of stack = " << size_of_stack << endl;
    int num_itr = 0;
    assert(a == f.fibonacci_iterative(i, num_itr));
    assert(a == f.fibonacci_recursion(i, num_itr));
  }
  cout << "Note that fibonacci_recursion sucks after 34\n";
}

/*----------------------------------------------------------------
test tower of hanoi
-----------------------------------------------------------------*/
void test_hanoi() {
  recursion f;
  cout << "-----------------------hanoi using recursion-----------------------\n";
  for (int i = 1; i < 5; ++i) {
    int num_itr = 0;
    str s;
    f.hanoi_recursion(i, num_itr,s);
    cout << s << "Number of itr = " << num_itr << endl;
  }

  cout << "-----------------------hanoi_using stack-----------------------\n";
  for (int i = 1; i < 10; ++i) {
    int size_of_stack = 0;
    str ss;
    f.hanoi_stack(i, size_of_stack,ss);
    cout << ss << "Size of stack = " << size_of_stack << endl;

    int num_itr = 0;
    str s;
    f.hanoi_recursion(i, num_itr, s);
    assert(ss == s);
  }
}


/*--------------------------------------------------------
main
-----------------------------------------------------------------*/
int main() {
  test_factorial();
  test_num_binary_digit();
  test_fibonacci();
  test_hanoi();
  return 0 ;
}

//EOF

