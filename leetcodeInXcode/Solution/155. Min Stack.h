//
//  155. Min Stack.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _55__Min_Stack_h
#define _55__Min_Stack_h

class MinStack {
public:
    MinStack() {}

    // 思路：使用辅助栈minStack，每个位置同步存储当前栈中的最小值，保证getMin为O(1)。
    void push(int val) {
        // 主栈正常入栈
        data.push(val);
        if (minStack.empty() || val <= minStack.top()) {
            // 新值更小或相等，入新最小值
            minStack.push(val);
        } else {
            // 新值更大，重复入当前最小值
            minStack.push(minStack.top());
        }
    }

    void pop() {
        data.pop();
        // 两栈同步出栈
        minStack.pop();
    }

    int top() {
        // 返回主栈栈顶
        return data.top();
    }

    int getMin() {
        // 返回辅助栈栈顶（当前最小值）
        return minStack.top();
    }

private:
    stack<int> data;
    stack<int> minStack;
};

class Solution {
public:
    void Test()
    {
        MinStack* obj = new MinStack();
        obj->push(-2);
        obj->push(0);
        obj->push(-3);
        cout << obj->getMin() << endl;
        obj->pop();
        cout << obj->top() << endl;
        cout << obj->getMin() << endl;
    }
};

#endif /* _55__Min_Stack_h */