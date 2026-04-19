//
//  33. Search in Rotated Sorted Array.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _3__Search_in_Rotated_Sorted_Array_h
#define _3__Search_in_Rotated_Sorted_Array_h

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int begin = 0;
        int end = nums.size() - 1;
        while(begin <= end){
            int mid = (begin + end) / 2;
            if(target == nums[mid]){//二分查找的框架，先把三个花括号写出来，再补里面的东西
                return mid;
            }
            else if(target < nums[mid]){
                if(nums[begin] < nums[mid]){//[begin，mid-1]递增区间[mid+1，end]旋转区间
                    if(target >= nums[begin]){
                        end = mid - 1;//target大于begin，在递增区间里搜索
                    }
                    else{
                        begin = mid + 1;//否则去旋转区间搜索
                    }
                }
                else if(nums[begin] > nums[mid]){//[begin，mid-1]旋转区间[mid+1，end]递增区间
                    end = mid - 1;//由于target小于mid，右侧又为递增区间，所以只能去左侧旋转区间搜索
                }
                else if(nums[begin] == nums[mid]){//此时是两个数字，因为/总是向下取整 如21 找1
                    begin = mid + 1;//两个数字，因为已经不是等于mid情况，所以只能去右侧搜索
                }
            }
            else if(target > nums[mid]){
                if(nums[begin] < nums[mid]){//[begin，mid-1]递增区间[mid+1，end]旋转区间
                    begin = mid + 1;//由于target大于mid，左侧又是递增区间，所以去右侧旋转区间搜索
                }
                else if(nums[begin] > nums[mid]){//[begin，mid-1]旋转区间[mid+1，end]递增区间
                    if(target >= nums[begin]){
                        end = mid - 1;//target大于mid，但是target也大于begin，说明大值在旋转区间里
                    }
                    else{
                        begin = mid + 1;//否则去递增区间搜索
                    }
                }
                else if(nums[begin] == nums[mid]){//此时是两个数字 如23 找3
                    begin = mid + 1;//两个数字，因为已经不是等于mid情况，所以只能去右侧搜索
                }
            }
        }
        return -1;
    }

    void Test()
    {
        vector<int> nums = {4,5,6,7,0,1,2};
        int target = 0;
        cout << search(nums, target) << endl;
    }
};

#endif /* _3__Search_in_Rotated_Sorted_Array_h */
