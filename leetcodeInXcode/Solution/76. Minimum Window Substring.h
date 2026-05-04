//
//  76. Minimum Window Substring.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _6__Minimum_Window_Substring_h
#define _6__Minimum_Window_Substring_h

class Solution {
public:
    // 思路：滑动窗口 + 双指针。右指针扩展窗口直到包含 t 中所有字符，
    // 然后左指针收缩窗口以寻找最小覆盖子串，维护 need 和 window 计数数组。
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        // t 中各字符的需求数量
        vector<int> need(256, 0);
        // 当前窗口中各字符的数量
        vector<int> window(256, 0);

        for (char c : t) {
            // 统计 t 中字符需求
            need[c]++;
        }

        // 窗口左右指针
        int left = 0, right = 0;
        // 窗口中满足 need 的字符种类数
        int match = 0;
        int minLen = INT_MAX;
        int minStart = 0;

        while (right < s.length()) {
            if (need[s[right]] > 0) {
                window[s[right]]++;
                if (window[s[right]] <= need[s[right]]) {
                    // 有效字符匹配数 +1
                    match++;
                }
            }
            // 右指针右移扩展窗口
            right++;

            // 窗口已覆盖 t 中所有字符，尝试收缩左边界
            while (match == t.length()) {
                if (right - left < minLen) {
                    // 更新最小长度
                    minLen = right - left;
                    // 记录起始位置
                    minStart = left;
                }

                if (need[s[left]] > 0) {
                    window[s[left]]--;
                    if (window[s[left]] < need[s[left]]) {
                        // 有效字符匹配数 -1，窗口不再满足条件
                        match--;
                    }
                }
                // 左指针右移收缩窗口
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }

    void Test()
    {
        string s = "ADOBECODEBANC";
        string t = "ABC";
        cout << minWindow(s, t) << endl;
    }
};

#endif /* _6__Minimum_Window_Substring_h */