//
//  recursion.cpp
//  recursion
//
//  Created by Zulfikar Ali Sahool Hameed on 10/21/14.
//  Copyright (c) 2014 Zulfikar Ali Sahool Hameed. All rights reserved.
//

#include "recursion.h"

long long recursion::factorial_iterative(int i, int& num_mult) {
    long long a = 1;
    for (int j = 1; j <= i; ++j) {
        a = a * j;
        num_mult++;
    }
    return a;
}

long long recursion::factorial_recursion(int i, int& num_rec) {
    if (i <= 1) {
        return 1;
    }
    return (i * factorial_recursion(i - 1 , ++num_rec));
}

int recursion::num_binary_digit_iterative(int i, int& num_itr) {
    int a = 0;
    while (i) {
        i = i / 2;
        num_itr++;
        a++;
    }
    return a;
}

int recursion::num_binary_digit_recursion(int i, int& num_rec) {
    if (i <= 1) {
        return 1;
    }
    return (1 + num_binary_digit_recursion(i/2, ++num_rec));
}

int recursion::fibonacci_iterative(int i, int& num_itr) {
    int a = 0, x = 0, y = 1;
    if (i == 0) {
        return 0;
    } else if (i == 1) {
        return 1;
    }
    for (int j = 2; j <= i; ++j) {
        a = x + y;
        x = y;
        y = a;
        num_itr++;
    }
    return a;
}


int recursion::fibonacci_recursion(int i, int& num_rec) {
    if (i == 0) {
        return 0;
    }
    if (i == 1) {
        return 1;
    }
    return fibonacci_recursion(i - 2, ++num_rec) + fibonacci_recursion(i - 1, ++num_rec);
}

void recursion::hanoi_recursion(int i, int& num_itr, str& s){
    num_itr++;
    //recursion::hanoi(i, 0, 1, 2, s);
}

void recursion::hanoi(int i, int src, int temp, int dest, str& s) {

    if(i == 0)
    {
        s = s + "Move disk " + i + " from " + src + " to " + dest;
    }
    else
    {
        hanoi(i - 1, src, temp, dest, s);
        s = s + "Move disk "  + i + " from " + src + " to " + dest;
        hanoi(i - 1, temp, dest, src, s);
    }
}

