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
    int climbStairs(int n) {
        if (n <= 3) {
            return n;
        }

        int a[2] = {2, 3};
        for (int i = 4; i <= n; i++) {
            int t = a[0] + a[1];
            a[0] = a[1];
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
