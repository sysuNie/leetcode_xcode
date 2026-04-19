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
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
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