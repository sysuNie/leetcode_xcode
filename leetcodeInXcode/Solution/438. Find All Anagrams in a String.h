//
//  438. Find All Anagrams in a String.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _38__Find_All_Anagrams_in_a_String_h
#define _38__Find_All_Anagrams_in_a_String_h

class Solution {
public:
    // 思路：滑动窗口 + 字符计数。用两个长度为 26 的数组分别记录 p 的字符频率和 s 中当前窗口的字符频率，窗口大小固定为 p.length()，每次右移时更新计数并比较。
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        // s 比 p 短，不可能存在变位词
        if (s.length() < p.length()) return result;

        // 记录 p 中每个字符的出现次数
        vector<int> pCount(26, 0);
        // 记录 s 的当前窗口中每个字符的出现次数
        vector<int> sCount(26, 0);

        // 统计 p 的字符频率
        for (char c : p) pCount[c - 'a']++;

        for (int i = 0; i < s.length(); i++) {
            // 窗口右端加入新字符
            sCount[s[i] - 'a']++;

            if (i >= p.length()) {
                // 窗口左端移出旧字符
                sCount[s[i - p.length()] - 'a']--;
            }

            if (i >= p.length() - 1 && sCount == pCount) {
                // 窗口内字符频率与 p 一致，记录起始位置
                result.push_back(i - p.length() + 1);
            }
        }

        return result;
    }

    void Test()
    {
        string s = "cbaebabacb";
        string p = "abc";
        vector<int> result = findAnagrams(s, p);
        for (int idx : result) {
            cout << idx << " ";
        }
        cout << endl;
    }
};

#endif /* _38__Find_All_Anagrams_in_a_String_h */