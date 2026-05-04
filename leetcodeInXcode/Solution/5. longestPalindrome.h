//
//  5. longestPalindrome.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef ___longestPalindrome_h
#define ___longestPalindrome_h

class Solution {
  public:
    // 思路：中心扩展法。遍历每个字符作为回文中心，分别考虑奇数长度和偶数长度两种情况
    string longestPalindrome(string s) {
        int len = s.size();
        if (len == 0 || len == 1)
            return s;
        // 最长回文子串起始位置
        int start = 0;
        // 最长回文子串终止位置
        int end = 0;
        // 最长回文子串的长度
        int mlen = 0;
        for (int i = 0; i < len; i++) {
            // 以单个字符为中心（奇数长度）
            int len1 = expendaroundcenter(s, i, i);
            // 以两个字符为中心（偶数长度）
            int len2 = expendaroundcenter(s, i, i + 1);
            mlen = max(max(len1, len2), mlen);
            // 找到更长的回文串，更新起止位置
            if (mlen > end - start + 1) {
                start = i - (mlen - 1) / 2;
                end = i + mlen / 2;
            }
        }
        // 截取最长回文子串
        return s.substr(start, mlen);
    }

    void Test() {
        string s = "cbbd";
        cout << longestPalindrome(s) << endl;
    }

  private:
    int expendaroundcenter(string s, int left, int right)
    // 计算以left和right为中心的回文串长度
    {
        int L = left;
        int R = right;
        while (L >= 0 && R < s.length() && s[R] == s[L]) {
            L--;
            R++;
        }
        return R - L - 1;
    }
};

#endif /* ___longestPalindrome_h */
