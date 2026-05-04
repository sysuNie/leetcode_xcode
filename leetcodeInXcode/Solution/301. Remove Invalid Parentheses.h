//
//  301. Remove Invalid Parentheses.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _01__Remove_Invalid_Parentheses_h
#define _01__Remove_Invalid_Parentheses_h

class Solution {
public:
    // 思路：BFS + 剪枝。逐层删除字符，第一层找到所有删除 1 个字符后的字符串，检查是否合法；一旦找到合法字符串，同一层其他结果也收集起来，不再继续下层搜索。
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        // 去重，避免重复处理相同字符串
        unordered_set<string> visited;

        queue<string> q;
        q.push(s);
        visited.insert(s);
        // 标记是否已找到最短合法字符串
        bool found = false;

        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            if (isValid(curr)) {
                // 找到合法字符串
                result.push_back(curr);
                found = true;
            }

            // 已找到最短结果，不再向下扩展
            if (found) continue;

            for (int i = 0; i < curr.length(); i++) {
                // 只删除括号
                if (curr[i] != '(' && curr[i] != ')') continue;

                // 删除第 i 个字符
                string next = curr.substr(0, i) + curr.substr(i + 1);
                if (visited.find(next) == visited.end()) {
                    q.push(next);
                    visited.insert(next);
                }
            }
        }

        return result;
    }

    // 判断字符串括号是否合法
    bool isValid(const string& s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') count++;
            else if (c == ')') count--;
            // 右括号过多，不合法
            if (count < 0) return false;
        }
        // 左右括号数量相等才合法
        return count == 0;
    }

    void Test()
    {
        string s = "()())()";
        vector<string> result = removeInvalidParentheses(s);
        for (const string& str : result) {
            cout << str << endl;
        }
    }
};

#endif /* _01__Remove_Invalid_Parentheses_h */