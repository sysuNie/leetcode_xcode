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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left = 0, right = 0;
        int sort[m + n];
        int cur;
        while (left < m || right < n) {
            if (left == m) {
                cur = nums2[right++];
            } else if (right == n) {
                cur = nums1[left++];
            } else if (nums1[left] < nums2[right])
            {
                cur = nums1[left++];
            } else {
                cur = nums2[right++];
            }
            
            sort[left + right - 1] = cur;
        }
        
        for (int i = 0; i < m + n; i++) {
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
