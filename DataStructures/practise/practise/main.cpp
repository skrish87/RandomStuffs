//
//  main.cpp
//  practise
//
//  Created by Zulfikar Ali Sahool Hameed on 11/19/14.
//  Copyright (c) 2014 Zulfikar Ali Sahool Hameed. All rights reserved.
//

#include <iostream>
using namespace std;


unsigned square_root(unsigned& num) {
    unsigned low = 1, high = num, mid = 0;
    while (low <= high) {
        mid = ((high-low)/2) + low;
        if ((mid * mid) == num) {
            return mid;
        } else if (mid * mid > num) {
            high = mid - 1;
        } else if (mid * mid < num) {
            low = mid + 1;
        }
    }
    return high;
}


long possiblePaths(unsigned& size, int i, int j) {
    if (i == size || j == size) {
        return 1;
    }
    return possiblePaths(size, i + 1, j) + possiblePaths(size, i, j + 1);
}

long findPaths(unsigned &size) {
    return possiblePaths(size, 1, 1);
}


int main(int argc, const char * argv[]) {
    
    unsigned number;
    unsigned size = 1;
    long result = 0;
    /*cout << "Enter number to find square root" << endl;
    cin >> number;
    cout << square_root(number) << endl;*/
    cout << "Enter the size of nxn matrix " << endl;
    cin >> size;
    result = findPaths(size);
    cout << result << endl;
    return 0;
}
