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
    int lengthOfLongestSubstring(string s) {
        int maxResult = 0;
        unordered_set<char> foundStr;
        int left = 0;
        for (int i = 0; i < s.length(); i++) {
            while (foundStr.find(s[i]) != foundStr.end()) {
                foundStr.erase(s[left]);
                left++;
            }
            maxResult = max(maxResult, i - left + 1);
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
