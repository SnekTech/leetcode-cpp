//
// Created by syf on 2023/3/15.
//

#ifndef LEETCODE_CPP_Q09_H
#define LEETCODE_CPP_Q09_H

#include <stack>

class CQueue {
public:
    using Stack = std::stack<int>;

    Stack pushStack, popStack;

    CQueue() = default;

    void appendTail(int value) {
        pushStack.push(value);
    }

    int deleteHead() {
        if (!popStack.empty())
        {
            int x = popStack.top();
            popStack.pop();
            return x;
        }

        if (pushStack.empty()) {
            return -1;
        }

        while (!pushStack.empty())
        {
            popStack.push(pushStack.top());
            pushStack.pop();
        }

        int val = popStack.top();
        popStack.pop();
        return val;
    }
};

#endif //LEETCODE_CPP_Q09_H
