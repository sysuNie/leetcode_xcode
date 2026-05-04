//
//  10. regularExpressionMatching.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _0__regularExpressionMatching_h
#define _0__regularExpressionMatching_h

class Solution {
  public:
    // 思路：动态规划。dp[i][j] 表示 s[0..i-1] 与 p[0..j-1] 是否匹配。
    // 分两种情况：字符直接匹配或遇到 '.' 时继承 dp[i-1][j-1]；
    // 遇到 '*' 时考虑重复0次、1次或多次。
    bool isMatch(string s, string p) {
        int lens = s.size();
        int lenp = p.size();
        // 因为包含了空字串的情况
        vector<vector<bool>> dp(lens + 1, vector<bool>(lenp + 1, false));
        // 初始化 两个空字串
        dp[0][0] = true;
        // 找出s为空 但p因为* 为空的情况
        for (int j = 1; j < lenp + 1; j++)
        {
            if (p[j] == '*') {
                dp[0][j + 1] = dp[0][j - 1];
            }
        }
        // 更新
        for (int i = 1; i < lens + 1; i++) {
            for (int j = 1; j < lenp + 1; j++) {
                // 情况1：符合，直接更新
                if (s[i - 1] == p[j - 1] || p[j - 1] == '.')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                // 情况2：考虑*的情况
                } else if (p[j - 1] == '*')
                {
                    if (s[i - 1] == p[j - 2] || p[j - 2] == '.') {
                        // 分别是  重复0次；重复一次；重复两次及以上！！！
                        dp[i][j] = dp[i][j - 2] || dp[i - 1][j - 2] || dp[i - 1][j];
                    // s[i-1] p[j-2]不匹配  *需要重复0次
                    } else
                    {
                        dp[i][j] = dp[i][j - 2];
                    }
                }
            }
        }
        return dp[lens][lenp];
    }

    void Test() {
        string s = "aa";
        string p = "a";
        cout << isMatch(s, p) << endl;
    }
};

#endif /* _0__regularExpressionMatching_h */
