//
//  truthtable.cpp
//  truthtable
//
//  Created by Zulfikar Ali Sahool Hameed on 9/30/14.
//  Copyright (c) 2014 Zulfikar Ali Sahool Hameed. All rights reserved.
//

#include "truthtable.h"
#include <iostream>
using namespace std;

class truthtable {
    public:
    truthtable(int number) {
        generateTruthTable(number);
    }
    
    void generateTruthTable(int number)
    {
        for (int level = 0; level < number; level++)
        {
            for (int i = (1 << number) - 1; i >= 0; i--)
                cout << ((i >> level) & 1);
            cout << "\n";
        }
    }
};