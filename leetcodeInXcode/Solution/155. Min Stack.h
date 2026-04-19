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

    void push(int val) {
        data.push(val);
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        } else {
            minStack.push(minStack.top());
        }
    }

    void pop() {
        data.pop();
        minStack.pop();
    }

    int top() {
        return data.top();
    }

    int getMin() {
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