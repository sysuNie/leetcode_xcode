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
    vector<int> countBits(int n) {
        vector<int> result(n + 1, 0);

        for (int i = 1; i <= n; i++) {
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