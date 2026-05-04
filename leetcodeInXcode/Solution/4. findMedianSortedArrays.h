//
//  4. findMedianSortedArrays.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef ___findMedianSortedArrays_h
#define ___findMedianSortedArrays_h

class Solution {
  public:
    // 思路：双指针模拟合并。遍历到中间位置即可，用l和r记录中位数相关的两个值
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int m = nums1.size();
        int n = nums2.size();
        // nums1指针
        int i = 0;
        // nums2指针
        int j = 0;
        // 上一次取出的值
        int l = 0;
        // 当前取出的值
        int r = 0;

        // 只需遍历到中位数的中间位置
        for (int x = 0; x <= (m + n) / 2; x++) {
            l = r;
            // 取两个数组中较小的当前元素
            if (i < m && (j >= n || nums1[i] < nums2[j]))
            {
                r = nums1[i++];
            }
            else
            {
                r = nums2[j++];
            }
        }

        // 奇数长度返回r，偶数长度返回(l+r)/2
        return (m + n) & 1 ? r : (l + r) / 2.0;
    }

    void Test() {
        vector<int> nums1 = {1, 2, 3};
        vector<int> nums2 = {4, 5, 6};
        double outs = findMedianSortedArrays(nums1, nums2);
        cout << outs << endl;
        system("pause");
    }
};

#endif /* ___findMedianSortedArrays_h */
