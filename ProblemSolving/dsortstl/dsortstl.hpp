//
//  dsortstl.hpp
//  dsortstl
//
//  Created by Zulfikar Ali Sahool Hameed on 11/09/14.
//  Copyright (c) 2014 Zulfikar Ali Sahool Hameed. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "dsortstl.h"
using namespace std;


template <typename T>
dsortstl<T>::dsortstl(vector<T>& d, int(*cf)(T&c1, T& c2)) : obj(d), cmpFunc(cf){
}

template <typename T>
dsortstl<T>::~dsortstl(){
}

template <typename T>
void dsortstl<T>::bubbleSort() {
    bool exchanged = false;
    int size = obj.size();
    int n = size, num_itr = 0, num_swap = 0, num_cmp = 0;
    do
    {
        num_itr++;
        exchanged = false;
        for (int i = 0; i < n - 1; i++)
        {
            int j = i + 1;
            num_cmp++;
            int result = cmpFunc(obj[i], obj[j]);
            if (result < 0)
            {
                num_swap++;
                exchanged = true;
                swap(i, j);
            }
        }
        n--;
    } while (exchanged);
    
    //Statistics
    int t = num_cmp + num_swap;
    double x = double(t) / double(size*size);
    cout << "Size : " << size << endl;
    cout << "No of comparisions : " << num_cmp << endl;
    cout << "No of swap : " << num_swap << endl;
    cout << "No of iterations : " << num_itr << endl;
    cout << "comparison + swap : " << t << endl;
    cout << "T(n) : " << x << endl;
    
}

template <typename T>
void dsortstl<T>::insertionSort() {
    bool exchanged = false;
    int num_swap = 0, num_itr = 0, num_cmp = 0;
    int size = obj.size();
    int n = size;
    for (int i = 1; i < n; i++){
        int pos;
        num_itr++;
        T current = obj[i];
        for (int j = i - 1; j >= pos; j--){
            num_swap++;
            num_cmp++;
            obj[j + 1] = obj[j];
        }
        obj[pos] = current;
    }
        //Statistics
        int t = num_cmp + num_swap;
        double x = double(t) / double(size*size);
        cout << "Size : " << size << endl;
        cout << "No of comparisions : " << num_cmp << endl;
        cout << "No of swap : " << num_swap << endl;
        cout << "No of iterations : " << num_itr << endl;
        cout << "comparison + swap : " << t << endl;
        cout << "T(n) : " << x << endl;

}

template <typename T>
void dsortstl<T>::mergeSort() {
    int size = obj.size();
    merge_sort(0, size);
}
    
template <typename T>
void dsortstl<T>::merge_sort(int start, int end) {
    if ((end - start) < 2)
        return;
    int mid = start + (end - start) / 2;
    merge_sort(start, mid);
    merge_sort(mid, end);
    merge(start, mid, end);
}

template <typename T>
void dsortstl<T>::merge(int start, int mid, int end) {

    int index = start, num_swap = 0, num_itr = 0, num_cmp = 0;
    int i1 = start, i2 = mid, j1 = mid, j2 = mid;
    vector<T> left;
    
    for (i1 = start; i1 < mid; i1++){
        left.push_back(obj[i1]);
    }
    vector<T> right;
    for (j1 = mid; j1 < end; j1++){
        right.push_back(obj[j1]);
    }
    
    i1 = start;
    i2 = mid;
    j1 = mid;
    j2 = end;
    unsigned int i = 0, j = 0;
    while ((i < left.size()) && (j < right.size())){
        num_cmp++;
        int k = cmpFunc(left[i], right[j]);
        if (k < 0){
            obj[index] = right[j];
            num_swap++;
            j++;
        }
        else{
            obj[index] = left[i];
            num_swap++;
            i++;
        }
        index = index + 1;
    }
    while (i < left.size()){
        obj[index++] = left[i++];
    }
    while (j < right.size()){
        obj[index++] = right[j++];
    }
    
    int size = obj.size();

    int t = num_cmp + num_swap;
    double x = double(t) / double(size*size);
    cout << "Size : " << size << endl;
    cout << "No of comparisions : " << num_cmp << endl;
    cout << "No of swap : " << num_swap << endl;
    cout << "No of iterations : " << num_itr << endl;
    cout << "comparison + swap : " << t << endl;
    cout << "T(n) : " << x << endl;

}

template <typename T>
void dsortstl<T>::print(){
    vector<T>::iterator itr;
    for (itr = obj.begin(); itr != obj.end(); ++itr) {
        cout << *itr << endl;
    }
}

template <typename T>
void dsortstl<T>::outputFile(const char * fileName)
{
    ofstream myfile;
    myfile.open(fileName);
    vector<T>::iterator itr;
    for (itr = _objects.begin(); itr != _objects.end(); ++itr) {
        myfile << *itr << endl;
    }
    myfile.close();
}
