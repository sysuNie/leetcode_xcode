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
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (s.length() < p.length()) return result;

        vector<int> pCount(26, 0);
        vector<int> sCount(26, 0);

        for (char c : p) pCount[c - 'a']++;

        for (int i = 0; i < s.length(); i++) {
            sCount[s[i] - 'a']++;

            if (i >= p.length()) {
                sCount[s[i - p.length()] - 'a']--;
            }

            if (i >= p.length() - 1 && sCount == pCount) {
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