//
//  20. Valid Parentheses.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _0__Valid_Parentheses_h
#define _0__Valid_Parentheses_h

class Solution {
  public:
    // 思路：利用栈的先进后出特性。遍历字符串，若当前字符与栈顶能配对则出栈，否则入栈。
    // 最终栈为空说明所有括号都正确匹配。
    bool isValid(string s) {
        // 用于存放未匹配的左括号
        stack<char> myStack;
        for (int i = 0; i < s.length(); i++) {
            if (myStack.empty() || !Match(myStack.top(), s[i])) {
                // 无法配对，入栈
                myStack.push(s[i]);
            } else {
                // 配对成功，出栈
                myStack.pop();
            }
        }
        if (myStack.empty())
            // 栈空说明全部匹配
            return true;
        else
            // 仍有未匹配的括号
            return false;
    }

    bool Match(char c1, char c2) {
        return c2 > c1 && c2 - c1 <= 2;
    }

    void Test() {
        string s = "()[]{}";
        cout << isValid(s) << endl;
    }
};

#endif /* _0__Valid_Parentheses_h */
