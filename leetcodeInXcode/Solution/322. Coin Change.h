//
//  322. Coin Change.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _22__Coin_Change_h
#define _22__Coin_Change_h

class Solution {
public:
    // 思路：动态规划（完全背包）。dp[i] 表示组成金额 i 所需的最少硬币数。初始化 dp[0]=0，其余为 INF。遍历每个金额，尝试用每种硬币更新最小值。
    int coinChange(vector<int>& coins, int amount) {
        // dp[i] 表示组成金额 i 的最少硬币数，初始化为 amount+1（不可能达到的值）
        vector<int> dp(amount + 1, amount + 1);
        // 组成金额 0 需要 0 个硬币
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            // 枚举每种硬币
            for (int coin : coins) {
                if (coin <= i) {
                    // 状态转移：使用一个 coin，剩余 i-coin 的最优解
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        // 如果仍为初始值，说明无法组成该金额
        return dp[amount] > amount ? -1 : dp[amount];
    }

    void Test()
    {
        vector<int> coins = {1, 2, 5};
        int amount = 11;
        cout << coinChange(coins, amount) << endl;
    }
};

#endif /* _22__Coin_Change_h */