//
//  215. Kth Largest Element in an Array.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _15__Kth_Largest_Element_in_an_Array_h
#define _15__Kth_Largest_Element_in_an_Array_h

class Solution {
public:
    // 思路：使用大顶堆（优先队列），将数组全部入堆后弹出k-1个元素，堆顶即为第k大。
    int findKthLargest(vector<int>& nums, int k) {
        // 默认大顶堆
        priority_queue<int> pq(nums.begin(), nums.end());

        for (int i = 0; i < k - 1; i++) {
            // 弹出前k-1个最大元素
            pq.pop();
        }

        // 当前堆顶即为第k大
        return pq.top();
    }

    void Test()
    {
        vector<int> nums = {3, 2, 1, 5, 6, 4};
        int k = 2;
        cout << findKthLargest(nums, k) << endl;
    }
};

#endif /* _15__Kth_Largest_Element_in_an_Array_h */