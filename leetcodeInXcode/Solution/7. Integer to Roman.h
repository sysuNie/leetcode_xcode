//
//  7. Integer to Roman.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _7__Integer_to_Roman_h
#define _7__Integer_to_Roman_h

class Solution {
public:
    string intToRoman(int num) {
        vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        string result;
        for (int i = 0; i < values.size(); i++) {
            while (num >= values[i]) {
                result += symbols[i];
                num -= values[i];
            }
        }
        return result;
    }

    void Test()
    {
        cout << intToRoman(3) << endl;
        cout << intToRoman(58) << endl;
        cout << intToRoman(1994) << endl;
    }
};

#endif /* _7__Integer_to_Roman_h */