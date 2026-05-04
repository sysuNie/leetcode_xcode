//
//  647. Palindromic Substrings.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _47__Palindromic_Substrings_h
#define _47__Palindromic_Substrings_h

class Solution {
public:
    // 思路：中心扩展法。枚举每个回文中心（包括字符之间），向两边扩展，直到不再是回文。共有 2n-1 个中心（n 个字符中心 + n-1 个间隙中心）。
    int countSubstrings(string s) {
        int count = 0;
        int n = s.length();

        for (int center = 0; center < 2 * n - 1; center++) {
            // 左指针
            int left = center / 2;
            // 右指针（处理奇偶长度回文）
            int right = left + center % 2;

            // 从中心向两边扩展，统计所有回文子串
            while (left >= 0 && right < n && s[left] == s[right]) {
                count++;
                left--;
                right++;
            }
        }

        return count;
    }

    void Test()
    {
        string s = "abc";
        cout << countSubstrings(s) << endl;
    }
};

#endif /* _47__Palindromic_Substrings_h */