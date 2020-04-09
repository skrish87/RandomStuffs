//
//  truthtabletest.cpp
//  truthtable
//
//  Created by Zulfikar Ali Sahool Hameed on 9/30/14.
//  Copyright (c) 2014 Zulfikar Ali Sahool Hameed. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include "truthtable.cpp"
#include <iostream>

using namespace std;

int main(int argc, const char * argv[])
{
    int n = 4;
    clock_t start = clock();
    truthtable a(4);
    clock_t end = clock();
    cout << "Running time for truthtable for n = " << n << " is " << double(end - start)/CLOCKS_PER_SEC << " secs " << endl;
    return 0;
    
    if (0) {
        /* Output:
         1010101010101010
         1100110011001100
         1111000011110000
         1111111100000000
         Running time for truthtable for n = 4 is 7.3e-05 secs
         Program ended with exit code: 0
         
         */
    }
}
