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
    // 思路：单调递减双端队列。队列中存储下标，保持对应值单调递减；
    // 队首始终是当前窗口最大值，窗口滑动时移除队首越界元素。
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        // 存储下标，对应值单调递减
        deque<int> dq;

        for (int i = 0; i < nums.size(); i++) {
            // 移除队尾小于等于当前值的元素（保持单调递减）
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            // 当前下标入队
            dq.push_back(i);

            // 队首元素已滑出窗口，移除
            if (dq.front() <= i - k) {
                dq.pop_front();
            }

            // 窗口达到大小k，记录当前最大值（队首）
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