//
//  139. Word Break.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _39__Word_Break_h
#define _39__Word_Break_h

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;

        for (int i = 1; i <= s.length(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && wordSet.find(s.substr(j, i - j)) != wordSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.length()];
    }

    void Test()
    {
        string s = "leetcode";
        vector<string> wordDict = {"leet", "code"};
        cout << (wordBreak(s, wordDict) ? "true" : "false") << endl;
    }
};

#endif /* _39__Word_Break_h */