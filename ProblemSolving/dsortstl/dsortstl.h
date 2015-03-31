//
//  dsortstl.h
//  dsortstl

//  Created by Zulfikar Ali Sahool Hameed on 11/09/14.
//  Copyright (c) 2014 Zulfikar Ali Sahool Hameed. All rights reserved.
//

#ifndef dsortstl_dsortstl_h
#define dsortstl_dsortstl_h

using namespace std;

#include <stdio.h>
#include <vector>

template <typename T>
class dsortstl {
public:
    dsortstl(vector<T>& d, int(*cf)(T& c1, T& c2));
    ~dsortstl();
    void print();
    void outputFile(const char * fileName);
    void bubbleSort();
    bool binarySearch(T& r, int first, int last, int& pos);
    void insertionSort();
    void mergeSort();
    
private:
    vector<T>& obj;
    int(*cmpFunc)(T& c1, T& c2);
    void swap(int i, int j);
    void merge_sort(int start, int end);
    void merge(int start, int mid, int end);
};

#include "dsortstl.hpp"
#endif