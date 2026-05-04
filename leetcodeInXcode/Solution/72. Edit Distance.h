//
//  72. Edit Distance.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _2__Edit_Distance_h
#define _2__Edit_Distance_h

class Solution {
public:
    // 思路：动态规划。dp[i][j] 表示 word1[0..i-1] 转成 word2[0..j-1] 的最少操作数。
    // 插入、删除、替换分别对应 dp[i][j-1]+1、dp[i-1][j]+1、dp[i-1][j-1]+1；若字符相同则无需操作。
    int minDistance(string word1, string word2) {
        // dp 数组，维度 +1 包含空串
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));

        for (int i = 0; i < dp.size(); i++) {
            // word1[0..i-1] 转成空串需 i 次删除
            dp[i][0] = i;
        }
        for (int j = 0; j < dp[0].size(); j++) {
            // 空串转成 word2[0..j-1] 需 j 次插入
            dp[0][j] = j;
        }

        for (int i = 1; i < dp.size(); i++) {
            for (int j = 1; j < dp[i].size(); j++) {
                // 先取插入、删除、替换三种操作的最小值 +1
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                if (word1[i - 1] == word2[j - 1]) {
                    // 字符相同，无需额外操作
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                }
            }
        }
        // 返回右下角结果
        return dp.back().back();
    }

    void Test()
    {
        string word1 = "horse";
        string word2 = "ros";
        cout << minDistance(word1, word2) << endl;
    }
};

作者：Ikaruga
//leetcode.cn/problems/edit-distance/solutions/189676/edit-distance-by-ikaruga/
链接：https:
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

#endif /* _2__Edit_Distance_h */
