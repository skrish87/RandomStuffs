//
//  complex.cpp
//  complex
//
//  Created by Zulfikar Ali Sahool Hameed on 10/7/14.
//  Copyright (c) 2014 Zulfikar Ali Sahool Hameed. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <iostream>
using namespace std;

class complex {

private:
    char *complexStr = nullptr;
    int real, imaginary;
    
public:
    complex(int real = 0, int imaginary = 0):real(real), imaginary(imaginary) {
        cout << "In constructor!!" << endl;
        constructComplextStr(real, imaginary);
    }
    
    complex(const complex &a) {
        cout << "In copy constructor" << endl;
        copy(a);
    }
    
    ~complex() {
        cout << "In destructor!! " << endl;
        release();
    }
    
    void setxy(int real, int imaginary) {
        this->real = real;
        this->imaginary = imaginary;
        constructComplextStr(this->real, this->imaginary);
    }
    
    void constructComplextStr(int real, int imaginary) {
        stringstream rstr, istr;
        int treal = real, timaginary = imaginary;
        char rsign = '+', isign = '+';
        
        if (real < 0) {
            rsign = '-';
            treal = real * -1;
        }
        if (imaginary < 0) {
            isign = '-';
            timaginary = imaginary * -1;
        }
        
        rstr << treal;
        istr << timaginary;
        
        int rlength = (int)strlen((rstr.str()).c_str());
        int ilength = (int)strlen((istr.str()).c_str());
        
        int length = rlength + ilength + 3;
        complexStr = new char[length];
        
        const char *rs = (rstr.str()).c_str();
        const char *is = (istr.str()).c_str();
        
        complexStr[0] = rsign;
        
        int j = 0;
        for (int i = 1;i <= rlength;++i) {
            complexStr[i] = rs[j++];
        }
        
        complexStr[rlength + 1] = isign;
        complexStr[rlength + 2] = 'i';
        
        j = 0;
        for (int i = rlength + 3; i <= length;++i) {
            complexStr[i] = is[j++];
        }
        complexStr[length] = '\0';

    }
    
    bool isEqual(complex &a, complex &b) {
        if (a.real == b.real && a.imaginary == b.imaginary) {
            return true;
        }
        return false;
    }
    
    void copy(const complex &a) {
        real = a.real;
        imaginary = a.imaginary;
        constructComplextStr(real, imaginary);
    }
    
    void release() {
        delete[] complexStr;
    }
    
    friend void operator<<(ostream& o, complex& a) {
        o << a.complexStr << endl ;
    }
    
    friend bool operator==(complex& a, complex& b) {
        if (a.isEqual(a, b) && b.isEqual(a, b)) {
            return true;
        }
        return false;
    }
    friend bool operator!=(complex &a, complex &b) {
        if (!a.isEqual(a, b) && !b.isEqual(a, b)) {
            return true;
        }
        return false;
    }
    complex& operator=(const complex &a) {
        if (this != &a) {
            release();
            copy(a);
        }
        return *this;
    }
};