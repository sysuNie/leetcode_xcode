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
    // 思路：动态规划。dp[i]表示字符串前i个字符能否被拆分，枚举最后一个单词的起始位置j，若dp[j]为真且s[j..i-1]在字典中，则dp[i]为真。
    bool wordBreak(string s, vector<string>& wordDict) {
        // 将字典转为哈希集合，O(1)查询
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.length() + 1, false);
        // 空字符串可以被拆分
        dp[0] = true;

        for (int i = 1; i <= s.length(); i++) {
            for (int j = 0; j < i; j++) {
                // 若前j个字符可拆分，且j到i的子串在字典中，则前i个字符可拆分
                if (dp[j] && wordSet.find(s.substr(j, i - j)) != wordSet.end()) {
                    dp[i] = true;
                    // 找到一个合法拆分即可，提前退出
                    break;
                }
            }
        }

        // 返回整个字符串是否可拆分
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