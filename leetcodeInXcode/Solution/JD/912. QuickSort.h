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
    // 思路：随机选择pivot并交换到末尾，双指针分区（i维护小于pivot的边界），
    //       将小于pivot的元素交换到左侧，最后将pivot放到正确位置并返回其索引。
    int radom_partition(vector<int>& nums, int l, int r)
    {
        // 随机选择pivot索引
        int randi = (rand() % (r - l + 1)) + l;
        // 将随机选中的pivot交换到区间末尾
        swap(nums[r], nums[randi]);
        
        // 以末尾元素作为pivot
        int pivot = nums[r];
        
        // i指向小于pivot的区域的最后一个位置
        int i = l - 1;
        // j遍历整个区间（除pivot外）
        for (int j = l; j < r; j++) {
            // 当前元素小于pivot，应放到左侧
            if (nums[j] < pivot) {
                // 扩展小于pivot的区域
                i = i + 1;
                // 将当前元素交换到左侧区域
                swap(nums[i], nums[j]);
            }
        }
        // 将pivot放到中间正确位置（i+1即为pivot的最终位置）
        swap(nums[i + 1], nums[r]);
        
        // 返回pivot的最终索引
        return i + 1;
    }
    
    // 思路：递归对pivot左右两侧子数组分别进行快速排序，直至子数组长度为1。
    void random_sort(vector<int>& nums, int l, int r)
    {
        // 递归终止条件：子数组长度大于1
        if (l < r)
        {
            // 获取pivot位置
            int pos = radom_partition(nums, l, r);
            // 递归排序左半部分（小于pivot）
            random_sort(nums, l, pos - 1);
            // 递归排序右半部分（大于pivot）
            random_sort(nums, pos + 1, r);
        }
    }
public:
    // 思路：快速排序（随机化版本）。初始化随机种子，对整个数组递归分治排序。
    vector<int> sortArray(vector<int>& nums) {
        // 设置随机种子，保证pivot选择的随机性
        srand((unsigned)time(NULL));
        // 对整个数组进行快速排序
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
