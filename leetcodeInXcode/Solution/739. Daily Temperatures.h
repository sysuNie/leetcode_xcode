//
//  739. Daily Temperatures.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _39__Daily_Temperatures_h
#define _39__Daily_Temperatures_h

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prevIdx = st.top();
                st.pop();
                result[prevIdx] = i - prevIdx;
            }
            st.push(i);
        }

        return result;
    }

    void Test()
    {
        vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
        vector<int> result = dailyTemperatures(temperatures);
        for (int r : result) {
            cout << r << " ";
        }
        cout << endl;
    }
};

#endif /* _39__Daily_Temperatures_h */