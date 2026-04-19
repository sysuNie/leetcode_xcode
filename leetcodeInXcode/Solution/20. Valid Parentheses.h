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
    bool isValid(string s) {
        stack<char> myStack;
        for (int i = 0; i < s.length(); i++) {
            if (myStack.empty() || !Match(myStack.top(), s[i])) {
                myStack.push(s[i]);
            } else {
                myStack.pop();
            }
        }
        if (myStack.empty())
            return true;
        else
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
