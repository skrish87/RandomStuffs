//
//  amicabletest.cpp
//  amicablepairs
//
//  Created by Zulfikar Ali Sahool Hameed on 9/29/14.
//  Copyright (c) 2014 Zulfikar Ali Sahool Hameed. All rights reserved.
//


#include "amicable.h"
#include "amicable.cpp"
#include <time.h>
#include <iostream>
using namespace std;

int main() {
    const int MAX = 100000;
    clock_t start = clock();
    amicable a(MAX);
    clock_t end = clock();
    cout << "Runtime for amicable " << double(end-start)/CLOCKS_PER_SEC << "secs" << endl;
    
    if (0) {
       /* Output of the program
        The following are amicable numbers
        220 and 284
        284 and 220
        1184 and 1210
        1210 and 1184
        2620 and 2924
        2924 and 2620
        5020 and 5564
        5564 and 5020
        6232 and 6368
        6368 and 6232
        10744 and 10856
        10856 and 10744
        12285 and 14595
        14595 and 12285
        17296 and 18416
        18416 and 17296
        63020 and 76084
        66928 and 66992
        66992 and 66928
        67095 and 71145
        69615 and 87633
        71145 and 67095
        76084 and 63020
        79750 and 88730
        87633 and 69615
        88730 and 79750
        Runtime for amicable 15.1197secs
        Program ended with exit code: 0 */
    }
}