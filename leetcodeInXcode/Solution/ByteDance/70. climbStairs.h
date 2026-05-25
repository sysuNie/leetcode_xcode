//
//  70. climbStairs.h
//  leetcodeInXcode
//
//  Created by niejikang on 13.5.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _0__climbStairs_h
#define _0__climbStairs_h

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }
        int a = 1, b = 2; // a = f(i-2), b = f(i-1)
        for (int i = 3; i <= n; i++) {
            int c = a + b; // 最后一步走1级或2级，共 f(i-2)+f(i-1) 种
            a = b;
            b = c;
        }
        
        return b;
    }
    
    void test(int n, int expected) {
        int result = climbStairs(n);
        std::cout << "n=" << n << " expected=" << expected
                  << " result=" << result
                  << (result == expected ? " ✅" : " ❌") << "\n";
    }
    
    
};

#endif /* _0__climbStairs_h */
