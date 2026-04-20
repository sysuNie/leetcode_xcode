//
//  120. Mini Path Triangle.h
//  leetcodeInXcode
//
//  Created by niejikang on 20.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _20__Mini_Path_Triangle_h
#define _20__Mini_Path_Triangle_h

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp(triangle.back());
        for (int i = triangle.size() - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                dp[j] = std::min(dp[j], dp[j + 1]) + triangle[i][j];
            }
        }
        return dp[0];
    }
};


#endif /* _20__Mini_Path_Triangle_h */
