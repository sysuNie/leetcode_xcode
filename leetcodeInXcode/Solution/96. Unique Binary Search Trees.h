//
//  96. Unique Binary Search Trees.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _6__Unique_Binary_Search_Trees_h
#define _6__Unique_Binary_Search_Trees_h

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - 1 - j];
            }
        }

        return dp[n];
    }

    void Test()
    {
        cout << numTrees(3) << endl;
    }
};

#endif /* _6__Unique_Binary_Search_Trees_h */