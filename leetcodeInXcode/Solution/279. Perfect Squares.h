//
//  279. Perfect Squares.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _79__Perfect_Squares_h
#define _79__Perfect_Squares_h

class Solution {
public:
    // 思路：动态规划。dp[i] 表示组成整数 i 所需的最少完全平方数个数。对于每个 i，枚举所有小于等于 i 的完全平方数 j*j，取 dp[i - j*j] + 1 的最小值。
    int numSquares(int n) {
        // dp[i] 表示组成 i 的最少完全平方数个数
        vector<int> dp(n + 1, INT_MAX);
        // 0 需要 0 个完全平方数
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            // 枚举所有小于等于 i 的完全平方数
            for (int j = 1; j * j <= i; j++) {
                // 状态转移：使用一个 j*j 后，剩余 i-j*j 的最优解
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }

        return dp[n];
    }

    void Test()
    {
        cout << numSquares(12) << endl;
        cout << numSquares(13) << endl;
    }
};

#endif /* _79__Perfect_Squares_h */