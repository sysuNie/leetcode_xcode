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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), [&](vector<int>& a, vector<int>& b) {return a[0] < b[0];});
        vector<int> current = intervals[0];
        for(const auto& interval : intervals) {
            if(interval[0] > current[1]) {
                ans.push_back(current);
                current = interval;
            }
            else {
                current[1] = max(current[1], interval[1]);
            }
        }
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
