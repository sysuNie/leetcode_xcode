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
    // 思路：使用栈处理嵌套结构。遇到数字时累加，遇到 '[' 将当前字符串和重复次数压栈并重置，遇到 ']' 弹出栈顶拼接重复后的字符串。
    string decodeString(string s) {
        // 存储 '[' 之前的字符串
        stack<string> strStack;
        // 存储重复次数
        stack<int> numStack;
        // 当前正在构建的字符串
        string current = "";
        // 当前累积的数字
        int num = 0;

        for (char c : s) {
            if (isdigit(c)) {
                // 累积数字（处理多位数）
                num = num * 10 + (c - '0');
            } else if (c == '[') {
                // 将重复次数压栈
                numStack.push(num);
                // 将当前字符串压栈
                strStack.push(current);
                // 重置数字
                num = 0;
                // 重置当前字符串，开始处理括号内内容
                current = "";
            } else if (c == ']') {
                // 获取重复次数
                int repeatTimes = numStack.top();
                numStack.pop();
                // 获取 '[' 之前的字符串
                string temp = strStack.top();
                strStack.pop();
                for (int i = 0; i < repeatTimes; i++) {
                    // 将括号内字符串重复指定次数
                    temp += current;
                }
                // 更新当前字符串
                current = temp;
            } else {
                // 普通字符直接追加
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