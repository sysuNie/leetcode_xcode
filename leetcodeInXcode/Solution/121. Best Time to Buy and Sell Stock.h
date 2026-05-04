//
//  121. Best Time to Buy and Sell Stock.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _21__Best_Time_to_Buy_and_Sell_Stock_h
#define _21__Best_Time_to_Buy_and_Sell_Stock_h

class Solution {
public:
    // 思路：一次遍历，维护截至当前的最小价格和最大利润。每天的价格与最小价格作差更新利润，同时更新最小价格。
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        // 记录历史最低价格
        int minPrice = prices[0];
        // 记录最大利润
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); i++) {
            // 计算当天卖出的利润并更新最大利润
            maxProfit = max(maxProfit, prices[i] - minPrice);
            // 更新历史最低价格
            minPrice = min(minPrice, prices[i]);
        }

        return maxProfit;
    }

    void Test()
    {
        vector<int> prices = {7, 1, 5, 3, 6, 4};
        cout << maxProfit(prices) << endl;
    }
};

#endif /* _21__Best_Time_to_Buy_and_Sell_Stock_h */