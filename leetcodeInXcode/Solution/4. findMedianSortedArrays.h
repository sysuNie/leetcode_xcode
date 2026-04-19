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
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        // 定义 i j 2个指针分别指针2个数组
        // 定义 l r 分别用来保存中位数；奇数个，只会用到 l 变量；偶数，会用到 l r 变量
        int m = nums1.size();
        int n = nums2.size();
        int i = 0;
        int j = 0;
        int l = 0;
        int r = 0;

        for (int x = 0; x <= (m + n) / 2; x++) {
            l = r;
            if (i < m && (j >= n || nums1[i] < nums2[j]))
            {
                r = nums1[i++];
            }
            else
            {
                r = nums2[j++];
            }
        }

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
