//
//  621. Task Scheduler.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _21__Task_Scheduler_h
#define _21__Task_Scheduler_h

class Solution {
public:
    // 思路：贪心算法。先统计每个任务的频率，按频率降序排列。计算最高频任务之间的空闲槽位，用其他任务填充这些槽位，若空闲槽位为负则无需等待。
    int leastInterval(vector<char>& tasks, int n) {
        // 统计每个任务的出现频率
        vector<int> freq(26, 0);
        for (char task : tasks) {
            // 将任务映射到 0-25 的索引
            freq[task - 'A']++;
        }

        // 按频率降序排列
        sort(freq.begin(), freq.end(), greater<int>());

        // 出现次数最多的任务的频率
        int maxFreq = freq[0];
        // 最大频率任务之间需要的空闲槽位
        int idleSlots = (maxFreq - 1) * n;

        for (int i = 1; i < 26; i++) {
            // 用其他任务填充空闲槽位
            idleSlots -= min(maxFreq - 1, freq[i]);
        }

        // 总时间 = 任务数 + 剩余空闲槽位
        return tasks.size() + max(0, idleSlots);
    }

    void Test()
    {
        vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
        int n = 2;
        cout << leastInterval(tasks, n) << endl;
    }
};

#endif /* _21__Task_Scheduler_h */