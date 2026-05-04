//
//  56. Merge Intervals.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _6__Merge_Intervals_h
#define _6__Merge_Intervals_h

class Solution {
public:
    // 思路：先按区间左端点排序，然后依次合并。维护当前合并区间 current，
    // 若下一个区间左端点大于 current 右端点，则 current 入答案并开启新区间；否则扩展右端点。
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        // 按左端点升序排序
        sort(intervals.begin(), intervals.end(), [&](vector<int>& a, vector<int>& b) {return a[0] < b[0];});
        // 初始化当前合并区间为第一个区间
        vector<int> current = intervals[0];
        for(const auto& interval : intervals) {
            // 当前区间与合并区间无重叠
            if(interval[0] > current[1]) {
                // 合并区间加入答案
                ans.push_back(current);
                // 开启新的合并区间
                current = interval;
            }
            else {
                // 有重叠，扩展右端点
                current[1] = max(current[1], interval[1]);
            }
        }
        // 加入最后一个合并区间
        ans.push_back(current);
        return ans;
    }

    void Test()
    {
        vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
        vector<vector<int>> result = merge(intervals);
        for(const auto& interval : result) {
            cout << interval[0] << " " << interval[1] << endl;
        }
    }
};


#endif /* _6__Merge_Intervals_h */
