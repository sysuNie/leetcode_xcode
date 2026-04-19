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
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char task : tasks) {
            freq[task - 'A']++;
        }

        sort(freq.begin(), freq.end(), greater<int>());

        int maxFreq = freq[0];
        int idleSlots = (maxFreq - 1) * n;

        for (int i = 1; i < 26; i++) {
            idleSlots -= min(maxFreq - 1, freq[i]);
        }

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