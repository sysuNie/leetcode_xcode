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
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        vector<int> need(256, 0);
        vector<int> window(256, 0);

        for (char c : t) {
            need[c]++;
        }

        int left = 0, right = 0;
        int match = 0;
        int minLen = INT_MAX;
        int minStart = 0;

        while (right < s.length()) {
            if (need[s[right]] > 0) {
                window[s[right]]++;
                if (window[s[right]] <= need[s[right]]) {
                    match++;
                }
            }
            right++;

            while (match == t.length()) {
                if (right - left < minLen) {
                    minLen = right - left;
                    minStart = left;
                }

                if (need[s[left]] > 0) {
                    window[s[left]]--;
                    if (window[s[left]] < need[s[left]]) {
                        match--;
                    }
                }
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