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
    // 思路：单调递减栈。维护一个从栈底到栈顶温度递减的栈，存储的是下标。遇到比栈顶温度高的天时，弹出栈顶并计算天数差。
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        // 初始化结果数组，默认为 0（表示后面没有更热的天气）
        vector<int> result(n, 0);
        // 单调递减栈，存储下标
        stack<int> st;

        for (int i = 0; i < n; i++) {
            // 当前温度高于栈顶温度时，栈顶元素的下一个更高温度就是当前天
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prevIdx = st.top();
                st.pop();
                // 计算天数差
                result[prevIdx] = i - prevIdx;
            }
            // 当前天下标入栈
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