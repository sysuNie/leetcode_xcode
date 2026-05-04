//
//  461. Hamming Distance.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _61__Hamming_Distance_h
#define _61__Hamming_Distance_h

class Solution {
public:
    // 思路：先对两个数进行异或运算，xor 结果中 1 的个数即为汉明距离。通过不断与 1 相与并右移，统计所有 1 的个数。
    int hammingDistance(int x, int y) {
        // 异或：相同位为 0，不同位为 1
        int xorVal = x ^ y;
        int count = 0;
        while (xorVal) {
            // 统计最低位是否为 1
            count += xorVal & 1;
            // 右移一位，检查下一位
            xorVal >>= 1;
        }
        return count;
    }

    void Test()
    {
        cout << hammingDistance(1, 4) << endl;
    }
};

#endif /* _61__Hamming_Distance_h */