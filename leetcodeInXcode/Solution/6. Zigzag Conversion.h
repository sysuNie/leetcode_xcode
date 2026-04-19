//
//  6. Zigzag Conversion.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _6__Zigzag_Conversion_h
#define _6__Zigzag_Conversion_h

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        vector<string> rows(min(numRows, (int)s.length()));
        int currentRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[currentRow] += c;
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }
            currentRow += goingDown ? 1 : -1;
        }

        string result;
        for (string& row : rows) {
            result += row;
        }
        return result;
    }

    void Test()
    {
        string s = "PAYPALISHIRING";
        int numRows = 3;
        cout << convert(s, numRows) << endl;
    }
};

#endif /* _6__Zigzag_Conversion_h */