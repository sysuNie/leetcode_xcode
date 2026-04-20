//
//  912. QuickSort.h
//  leetcodeInXcode
//
//  Created by niejikang on 20.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _12__QuickSort_h
#define _12__QuickSort_h

class Solution {
    int radom_partition(vector<int>& nums, int l, int r)
    {
        int randi = (rand() % (r - l + 1)) + l;
        swap(nums[r], nums[randi]);
        
        int pivot = nums[r];
        
        int i = l - 1;
        for (int j = l; j < r; j++) {
            if (nums[j] < pivot) {
                i = i + 1;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[r]);
        
        return i + 1;
    }
    
    void random_sort(vector<int>& nums, int l, int r)
    {
        if (l < r)
        {
            int pos = radom_partition(nums, l, r);
            random_sort(nums, l, pos - 1);
            random_sort(nums, pos + 1, r);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        srand((unsigned)time(NULL));
        random_sort(nums, 0, nums.size() - 1);
        return nums;
    }
    
    vector<int> Test()
    {
        int input[12] = {0,1,3,6,5,7,9,3,4,8,6,2};
        vector<int> weights;
        weights.insert(weights.begin(), input, input + 12);
        return sortArray(weights);
    }
};

#endif /* _12__QuickSort_h */
