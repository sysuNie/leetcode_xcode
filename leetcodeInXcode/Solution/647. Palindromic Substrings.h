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
    int countSubstrings(string s) {
        int count = 0;
        int n = s.length();

        for (int center = 0; center < 2 * n - 1; center++) {
            int left = center / 2;
            int right = left + center % 2;

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