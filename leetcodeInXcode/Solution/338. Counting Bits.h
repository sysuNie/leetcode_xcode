//
//  338. Counting Bits.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _38__Counting_Bits_h
#define _38__Counting_Bits_h

class Solution {
public:
    // 思路：动态规划。result[i] 表示数字 i 的二进制中 1 的个数。利用 i >> 1 和 i 的关系：i 右移一位后最低位丢失，因此 result[i] = result[i/2] + (i 的最低位)。
    vector<int> countBits(int n) {
        // result[i] 表示 i 的二进制中 1 的个数
        vector<int> result(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            // i>>1 去掉最低位，i&1 得到最低位
            result[i] = result[i >> 1] + (i & 1);
        }

        return result;
    }

    void Test()
    {
        vector<int> result = countBits(5);
        for (int num : result) {
            cout << num << " ";
        }
        cout << endl;
    }
};

#endif /* _38__Counting_Bits_h */