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
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); i++) {
            maxProfit = max(maxProfit, prices[i] - minPrice);
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