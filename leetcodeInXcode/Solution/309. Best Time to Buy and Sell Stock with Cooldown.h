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
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        int n = prices.size();
        vector<int> dp(n, 0);
        int minPrice = prices[0];

        for (int i = 1; i < n; i++) {
            minPrice = min(minPrice, prices[i] - (i >= 2 ? dp[i - 2] : 0));
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