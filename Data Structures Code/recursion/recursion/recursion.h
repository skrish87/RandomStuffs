//
//  recursion.h
//  recursion
//
//  Created by Zulfikar Ali Sahool Hameed on 10/21/14.
//  Copyright (c) 2014 Zulfikar Ali Sahool Hameed. All rights reserved.
//

#ifndef __recursion__recursion__
#define __recursion__recursion__

#include <stdio.h>
#include "str.h"

#endif /* defined(__recursion__recursion__) */

class recursion {
public:
    long long factorial_iterative(int i, int& num_mult);
    long long factorial_recursion(int i, int& num_rec);
    
    int num_binary_digit_iterative(int i, int& num_mult);
    int num_binary_digit_recursion(int i, int& num_rec);
    
    int fibonacci_iterative(int i, int& num_itr);
    int fibonacci_recursion(int i, int& num_rec);
    
    void hanoi_recursion(int i, int& num_itr, str& s);
    void hanoi(int i, int src, int temp, int dest, str &s);
};