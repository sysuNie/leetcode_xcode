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
    int hammingDistance(int x, int y) {
        int xorVal = x ^ y;
        int count = 0;
        while (xorVal) {
            count += xorVal & 1;
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