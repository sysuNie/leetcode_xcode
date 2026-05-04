//
//  309. Best Time to Buy and Sell Stock with Cooldown.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _09__Best_Time_to_Buy_and_Sell_Stock_with_Cooldown_h
#define _09__Best_Time_to_Buy_and_Sell_Stock_with_Cooldown_h

class Solution {
public:
    // 思路：动态规划。dp[i] 表示前 i 天的最大利润。minPrice 维护买入的最低成本，卖出后有一天冷却期，所以用 dp[i-2] 来调整买入成本。
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        int n = prices.size();
        // dp[i] 表示前 i 天能获得的最大利润
        vector<int> dp(n, 0);
        // 记录最低买入成本
        int minPrice = prices[0];

        for (int i = 1; i < n; i++) {
            // 买入时需扣除冷却期前的利润，即 prices[i] - dp[i-2] 才是真正的买入成本
            minPrice = min(minPrice, prices[i] - (i >= 2 ? dp[i - 2] : 0));
            // 状态转移：不操作 或 卖出
            dp[i] = max(dp[i - 1], prices[i] - minPrice);
        }

        return dp[n - 1];
    }

    void Test()
    {
        vector<int> prices = {1, 2, 3, 0, 2};
        cout << maxProfit(prices) << endl;
    }
};

#endif /* _09__Best_Time_to_Buy_and_Sell_Stock_with_Cooldown_h */