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
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (coin <= i) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

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