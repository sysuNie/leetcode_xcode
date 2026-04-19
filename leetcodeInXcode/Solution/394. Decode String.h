//
//  394. Decode String.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _94__Decode_String_h
#define _94__Decode_String_h

class Solution {
public:
    string decodeString(string s) {
        stack<string> strStack;
        stack<int> numStack;
        string current = "";
        int num = 0;

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '[') {
                numStack.push(num);
                strStack.push(current);
                num = 0;
                current = "";
            } else if (c == ']') {
                int repeatTimes = numStack.top();
                numStack.pop();
                string temp = strStack.top();
                strStack.pop();
                for (int i = 0; i < repeatTimes; i++) {
                    temp += current;
                }
                current = temp;
            } else {
                current += c;
            }
        }

        return current;
    }

    void Test()
    {
        string s = "3[a2[c]]";
        cout << decodeString(s) << endl;
    }
};

#endif /* _94__Decode_String_h */