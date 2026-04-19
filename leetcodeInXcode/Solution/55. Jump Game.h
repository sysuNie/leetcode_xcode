//
//  55. Jump Game.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _5__Jump_Game_h
#define _5__Jump_Game_h

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() <= 1) {
            return true;
        }
        int nearest = nums.size() - 1;
        for(int i = nums.size() - 2; i >= 0; --i) {
            if(i + nums[i] >= nearest) {
                nearest = i;
            }
        }
        return nearest == 0;
    }

    void Test()
    {
        vector<int> nums = {2,3,1,1,4};
        cout << (canJump(nums) ? "true" : "false") << endl;
    }
};

#endif /* _5__Jump_Game_h */
