//
//  amicable.cpp
//  amicablepairs
//
//  Created by Zulfikar Ali Sahool Hameed on 9/29/14.
//  Copyright (c) 2014 Zulfikar Ali Sahool Hameed. All rights reserved.
//

#include "amicable.h"
#include "util.h"
#include <time.h>
#include <iostream>
using namespace std;

class amicable {
public:
    amicable(const int MAX) {
        generateAmicablePairs(MAX);
    }
    
    int sumFactors(int number)
    {
        int sum = 0, half = (number / 2) + 1;
        for (int i = 1; i < half; i++)
        {
            if (!(number % i))
            {
                sum += i;
            }
        }
        return sum;
    }
    
    
    void generateAmicablePairs(const int MAX)
    {
        cout << "The following are amicable numbers" << endl;
        for(int i = 1; i <= MAX; i++)
        {
            int j = sumFactors(i);
            if ((sumFactors(j) == i) && (i != j))
            {
                cout << i << " and " << j << "\n";
            }
        }
        
    }

};