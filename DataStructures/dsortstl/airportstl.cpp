//
//  airportstl.cpp
//  dsortstl
//
//  Created by Zulfikar Ali Sahool Hameed on 11/09/14.
//  Copyright (c) 2014 Zulfikar Ali Sahool Hameed. All rights reserved.
//

#include "dsortstl.h"

#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class flight {
private:
    char* dest;
    char* name;
    char* dtime;
    char* fno;

public:
    flight(char*& dest, char*& name,char*& dtime, char*& fno) {
        dest = dest;
        name = name;
        dtime = dtime;
        fno = fno;
    }

    char* getDestination() {
        return dest;
    }
    char* getName() {
        return name;
    }
    char* getTime() {
        return dtime;
    }
    char* getNumber() {
        return fno;
    }
    
    flight() {
    }
    
    friend ostream& operator<<(ostream& o, flight& c){
        o << c.getTime() << " " << c.getDestination() << " " << c.getName
        () << " " << c.getNumber() ;
        return o;
    }
};



void readInput(vector<flight>& flights) {
    ifstream file("flights.dat");
    string linebuffer;
    while (file && getline(file, linebuffer)){
        if (linebuffer.length() != 0){
            char* dest = nullptr, * name = nullptr, *time = nullptr, * no = nullptr;
            int delimiterCount = 1;
            int start = 0, end = 0;
            size_t found = linebuffer.find("|");
            while (found != -1){
                end = found;
                string str = linebuffer.substr(start, end - start);
                if (delimiterCount == 1){
                    dest = new char[str.size() + 1];
                    strcpy(dest, str.c_str());
                }
                if (delimiterCount == 2){
                    name = new char[str.size() + 1];
                    strcpy(name, str.c_str());
                }
                if (delimiterCount == 3){
                    time = new char[str.size() + 1];
                    strcpy(time, str.c_str());
                }
                if (delimiterCount == 4){
                    no = new char[str.size() + 1];
                    strcpy(no, str.c_str());
                }

                found = linebuffer.find("|", end + 1);
                start = end + 1;
                delimiterCount++;
            }
            flight f1(dest, name, time, no);
            flights.push_back(f1);
        }
    }
}

int compare(flight& c1, flight& c2) {
    int result = strcmp(c1.getTime(), c2.getTime());
    if (result == 0){
        result = strcmp(c1.getDestination(), c2.getDestination());
        if (result == 0){
            result = strcmp(c1.getName(), c2.getName());
            if (result == 0){
                result = strcmp(c1.getNumber(), c2.getNumber());
            }
        }
    }
    return result;
}


int main() {
    vector<flight> flights;
    readInput(flights);
    dsortstl<flight> bubble(flights, compare);
    bubble.bubbleSort();
    bubble.outputFile("bubble.dat");

    readInput(flights);
    dsortstl<flight> insertion(flights, compare);
    insertion.insertionSort();
    insertion.outputFile("insertion.dat");

    readInput(flights);
    dsortstl<flight> merge(flights, compare);
    merge.insertionSort();
    merge.outputFile("merge.dat");

    return 0;
}
