//
//  239. Sliding Window Maximum.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _39__Sliding_Window_Maximum_h
#define _39__Sliding_Window_Maximum_h

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq;

        for (int i = 0; i < nums.size(); i++) {
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);

            if (dq.front() <= i - k) {
                dq.pop_front();
            }

            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }

    void Test()
    {
        vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
        int k = 3;
        vector<int> result = maxSlidingWindow(nums, k);
        for (int num : result) {
            cout << num << " ";
        }
        cout << endl;
    }
};

#endif /* _39__Sliding_Window_Maximum_h */