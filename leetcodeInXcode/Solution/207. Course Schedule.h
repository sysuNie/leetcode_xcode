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
    // 思路：拓扑排序（Kahn算法）。构建有向图和入度表，从入度为0的课程开始BFS，若能学完所有课程则无环。
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        // 邻接表存储图
        vector<vector<int>> graph(numCourses);
        // 每个课程的入度
        vector<int> inDegree(numCourses, 0);

        for (auto& pre : prerequisites) {
            // pre.second -> pre.first
            graph[pre.second].push_back(pre.first);
            // 入度加1
            inDegree[pre.first]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            // 入度为0的课程入队（无先修课）
            if (inDegree[i] == 0) q.push(i);
        }

        // 已学习的课程数
        int count = 0;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            count++;

            // 释放后续课程的入度
            for (int next : graph[course]) {
                inDegree[next]--;
                // 入度降为0，可以学习
                if (inDegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        // 是否所有课程都学完
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