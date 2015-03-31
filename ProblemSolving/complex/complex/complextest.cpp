//
//  complextest.cpp
//  complex
//
//  Created by Zulfikar Ali Sahool Hameed on 10/7/14.
//  Copyright (c) 2014 Zulfikar Ali Sahool Hameed. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "complex.cpp"

int main() {
    complex c1(2,3);
    cout << c1;
    complex c2(27,-200);
    cout << c2;
    complex c3(-34, -12);
    cout << c3;
    complex c4(-18, -99);
    cout << c4;
    c2.setxy(2, 3);
    cout << c2;

    if (c1 == c2) {
        cout << "c1 is equal to c2" << endl;
    } else {
        cout << "c1 is not equal to c2" << endl;
    }
    
    if (c1 != c3) {
        cout << "c1 is not equal to c3" << endl;
    } else {
        cout << "c1 is equal to c3" << endl;
    }
    complex *c5 = new complex(-200, -800);
    cout << *c5;
    delete c5;
    c1 = c2 = c3 = c4;
    cout << c3;
    
    if (0) {
        /*In constructor!!
        +2+i3
        In constructor!!
        +27-i200
        In constructor!!
        -34-i12
        In constructor!!
        -18-i99
        +2+i3
        c1 is equal to c2
        c1 is not equal to c3
        In constructor!!
        -200-i800
        In destructor!!
        -18-i99
        In destructor!! 
        In destructor!! 
        In destructor!! 
        In destructor!! 
        Program ended with exit code: 0 */
    }
    return 0;
}