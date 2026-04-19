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
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int8_t> is_valid(n);
        stack<int> st; // 未配对的左括号的下标

        // 标记哪些括号是配对的
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i); // 保存左括号的下标
            } else if (!st.empty()) { // 右括号与栈顶的左括号配对
                is_valid[i] = is_valid[st.top()] = true;
                st.pop();
            }
        }

        // 最长有效括号即为 is_valid 中的最长连续 true
        int ans = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            if (is_valid[i]) {
                cnt++; // 连续 true 的个数
                ans = max(ans, cnt);
            } else {
                cnt = 0; // 重置计数器
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
