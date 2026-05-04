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
    // 思路：模拟Z字形行走过程，按行收集字符。维护当前行号和走向（向下/向上），
    // 到达首尾行时反转方向，最后将各行拼接即为结果。
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) {
            // 只有1行或行数不小于长度时，直接返回原串
            return s;
        }

        vector<string> rows(min(numRows, (int)s.length()));
        // 当前字符所属行
        int currentRow = 0;
        // 当前走向，true为向下，false为向上
        bool goingDown = false;

        for (char c : s) {
            // 将字符放入当前行
            rows[currentRow] += c;
            if (currentRow == 0 || currentRow == numRows - 1) {
                // 到达首尾行时反转方向
                goingDown = !goingDown;
            }
            // 根据走向移动到下一行
            currentRow += goingDown ? 1 : -1;
        }

        string result;
        for (string& row : rows) {
            // 按顺序拼接所有行
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