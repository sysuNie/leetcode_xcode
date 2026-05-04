//
//  253. Meeting Rooms II.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _53__Meeting_Rooms_II_h
#define _53__Meeting_Rooms_II_h

class Solution {
public:
    // 思路：将开始时间和结束时间分别排序，使用双指针遍历。当一个会议开始时，如果开始时间小于当前最早结束时间，则需要新增会议室；否则复用已释放的会议室。
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        vector<int> starts;
        vector<int> ends;
        for (auto& interval : intervals) {
            // 收集所有开始时间
            starts.push_back(interval[0]);
            // 收集所有结束时间
            ends.push_back(interval[1]);
        }

        // 排序开始时间
        sort(starts.begin(), starts.end());
        // 排序结束时间
        sort(ends.begin(), ends.end());

        // 需要的会议室数量
        int rooms = 0;
        // 指向最早结束的会议
        int endIdx = 0;

        for (int i = 0; i < starts.size(); i++) {
            if (starts[i] < ends[endIdx]) {
                // 最早结束的会议还未结束，需要新开会议室
                rooms++;
            } else {
                // 已有会议室空闲，复用该会议室
                endIdx++;
            }
        }

        return rooms;
    }

    void Test()
    {
        vector<vector<int>> intervals = {{0, 30},{5, 10},{15, 20}};
        cout << minMeetingRooms(intervals) << endl;
    }
};

#endif /* _53__Meeting_Rooms_II_h */