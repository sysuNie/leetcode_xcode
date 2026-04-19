//
//  75. Sort Colors.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _5__Sort_Colors_h
#define _5__Sort_Colors_h

class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> num012(3);
        for(auto num : nums) {
            num012[num]++;
        }
        for(int i = 0; i < nums.size(); ++i) {
            if(i < num012[0]) {
                nums[i] = 0;
            }
            else if(i < num012[0] + num012[1]) {
                nums[i] = 1;
            }
            else {
                nums[i] = 2;
            }
        }
    }

    void Test()
    {
        vector<int> nums = {2,0,2,1,1,0};
        sortColors(nums);
        for(int num : nums) {
            cout << num << " ";
        }
        cout << endl;
    }
};

#endif /* _5__Sort_Colors_h */
