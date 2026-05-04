//
//  88. Merge Sorted Array.h
//  leetcodeInXcode
//
//  Created by niejikang on 20.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _8__Merge_Sorted_Array_h
#define _8__Merge_Sorted_Array_h

class Solution {
public:
    // 思路：双指针合并。使用两个指针分别遍历nums1的有效元素和nums2，
    //       每次取较小值放入临时数组，最后将结果拷贝回nums1。
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // left指向nums1，right指向nums2
        int left = 0, right = 0;
        // 临时数组存放合并结果
        int sort[m + n];
        int cur;
        // 任一数组未遍历完则继续
        while (left < m || right < n) {
            if (left == m) {
                // nums1已遍历完，取nums2剩余元素
                cur = nums2[right++];
            } else if (right == n) {
                // nums2已遍历完，取nums1剩余元素
                cur = nums1[left++];
            } else if (nums1[left] < nums2[right])
            {
                // nums1当前元素较小，取nums1[left]
                cur = nums1[left++];
            } else {
                // nums2当前元素较小或相等，取nums2[right]
                cur = nums2[right++];
            }
            
            // 放入临时数组的对应位置
            sort[left + right - 1] = cur;
        }
        
        for (int i = 0; i < m + n; i++) {
            // 将合并结果拷贝回nums1
            nums1[i] = sort[i];
        }
    }
    
    void Test()
    {
        int input[6] = {1,2,3,0,0,0};
        int input1[3] = {2,5,6};
        vector<int> nums1;
        nums1.insert(nums1.begin(), input, input + 6);
        vector<int> nums2;
        nums2.insert(nums2.begin(), input1, input + 3);
        merge(nums1, 3, nums2, 3);
    }
};

#endif /* _8__Merge_Sorted_Array_h */
