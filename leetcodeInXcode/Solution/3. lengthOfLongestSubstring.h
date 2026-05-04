//
//  3. lengthOfLongestSubstring.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef ___lengthOfLongestSubstring_h
#define ___lengthOfLongestSubstring_h

class Solution {
public:
    // 思路：滑动窗口。用双指针维护无重复字符的子串，右指针扩展，遇到重复字符时左指针收缩
    int lengthOfLongestSubstring(string s) {
        int maxResult = 0;
        // 记录窗口内的字符
        unordered_set<char> foundStr;
        // 窗口左边界
        int left = 0;
        for (int i = 0; i < s.length(); i++) {
            // 当遇到重复字符时，左指针右移直到无重复
            while (foundStr.find(s[i]) != foundStr.end()) {
                foundStr.erase(s[left]);
                left++;
            }
            // 更新最大长度
            maxResult = max(maxResult, i - left + 1);
            // 将当前字符加入窗口
            foundStr.insert(s[i]);
        }
        
        return maxResult;
    }
    
    void Test()
    {
        string s = "abcabcbb";
        cout << lengthOfLongestSubstring(s) << endl;
    }
};

#endif /* ___lengthOfLongestSubstring_h */
