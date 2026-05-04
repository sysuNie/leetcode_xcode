//
//  32. Longest Valid Parentheses.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _2__Longest_Valid_Parentheses_h
#define _2__Longest_Valid_Parentheses_h

class Solution {
public:
    // 思路：先用栈标记所有配对的括号位置，再遍历标记数组找出最长连续配对段。
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int8_t> is_valid(n);
        // 未配对的左括号的下标
        stack<int> st;

        // 标记哪些括号是配对的
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                // 保存左括号的下标
                st.push(i);
            // 右括号与栈顶的左括号配对
            } else if (!st.empty()) {
                is_valid[i] = is_valid[st.top()] = true;
                st.pop();
            }
        }

        // 最长有效括号即为 is_valid 中的最长连续 true
        int ans = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            if (is_valid[i]) {
                // 连续 true 的个数
                cnt++;
                ans = max(ans, cnt);
            } else {
                // 重置计数器
                cnt = 0;
            }
        }
        return ans;
    }

    void Test()
    {
        string s = ")()())";
        cout << longestValidParentheses(s) << endl;
    }
};

#endif /* _2__Longest_Valid_Parentheses_h */
