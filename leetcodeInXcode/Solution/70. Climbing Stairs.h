//
//  70. Climbing Stairs.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _0__Climbing_Stairs_h
#define _0__Climbing_Stairs_h

class Solution {
public:
    // 思路：动态规划，斐波那契数列。到达第 n 阶的方法数 = 到达第 n-1 阶的方法数 + 到达第 n-2 阶的方法数。
    // 使用滚动数组优化空间，只保留前两个状态。
    int climbStairs(int n) {
        if (n <= 3) {
            return n;
        }

        // a[0] 保存 n-2 的结果，a[1] 保存 n-1 的结果
        int a[2] = {2, 3};
        for (int i = 4; i <= n; i++) {
            // 当前阶数方法数 = 前两阶方法数之和
            int t = a[0] + a[1];
            // 滚动更新：前一个状态变为新的 n-2
            a[0] = a[1];
            // 当前状态变为新的 n-1
            a[1] = t;
        }

        return a[1];
    }

    void Test()
    {
        cout << climbStairs(5) << endl;
    }
};

#endif /* _0__Climbing_Stairs_h */
