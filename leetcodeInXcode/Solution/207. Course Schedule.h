//
//  207. Course Schedule.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _07__Course_Schedule_h
#define _07__Course_Schedule_h

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);

        for (auto& pre : prerequisites) {
            graph[pre.second].push_back(pre.first);
            inDegree[pre.first]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) q.push(i);
        }

        int count = 0;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            count++;

            for (int next : graph[course]) {
                inDegree[next]--;
                if (inDegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        return count == numCourses;
    }

    void Test()
    {
        int numCourses = 2;
        vector<pair<int, int>> prerequisites = {{1, 0}};
        cout << (canFinish(numCourses, prerequisites) ? "true" : "false") << endl;
    }
};

#endif /* _07__Course_Schedule_h */