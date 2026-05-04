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
    // 思路：动态规划。dp[i]表示i个节点能组成的独特BST数量，枚举根节点，左子树有j个节点，右子树有i-1-j个节点。
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        // 空树也是一种情况
        dp[0] = 1;
        // 单个节点只有一种BST
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                // 左子树方案数 * 右子树方案数
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