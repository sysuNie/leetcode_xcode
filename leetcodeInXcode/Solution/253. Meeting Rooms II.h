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
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        vector<int> starts;
        vector<int> ends;
        for (auto& interval : intervals) {
            starts.push_back(interval[0]);
            ends.push_back(interval[1]);
        }

        sort(starts.begin(), ends.end());
        sort(ends.begin(), ends.end());

        int rooms = 0;
        int endIdx = 0;

        for (int i = 0; i < starts.size(); i++) {
            if (starts[i] < ends[endIdx]) {
                rooms++;
            } else {
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