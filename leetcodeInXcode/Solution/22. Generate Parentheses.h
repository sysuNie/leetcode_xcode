//
//  22. Generate Parentheses.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _2__Generate_Parentheses_h
#define _2__Generate_Parentheses_h

class Solution {
  public:
    vector<string> ans;

    // 思路：回溯/DFS，在当前字符串的每个合法位置插入 "()" 来构造新字符串。
    // 当已用完 n 对括号时，记录结果。
    vector<string> generateParenthesis(int n) {
        ans.clear();
        checkNextLevel("", 0, n);
        return ans;
    }

    void checkNextLevel(string now, int ptr, int n) {
        if (n == 0) {
            // 已用完n对括号，记录结果
            ans.push_back(now);
            return;
        }

        while (ptr <= now.length()) {
            if (now[ptr] == ')' || ptr == now.length()) {
                // 在当前位置插入一对括号并递归
                checkNextLevel(now.substr(0, ptr) + "()" + now.substr(ptr), ptr + 1, n - 1);
            }
            ptr++;
        }
    }

    void Test() {
        vector<string> ans = generateParenthesis(4);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << endl;
        }
    }
};

#endif /* _2__Generate_Parentheses_h */
