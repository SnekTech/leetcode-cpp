//
// Created by syf on 2023/3/15.
//

#ifndef LEETCODE_CPP_Q30_H
#define LEETCODE_CPP_Q30_H

#include <stack>

class MinStack {
public:
    using Stack = std::stack<int>;
    Stack stack, minStack;
    /** initialize your data structure here. */
    MinStack() = default;

    void push(int x) {
        stack.push(x);
        if (minStack.empty() || x <= min()) {
            minStack.push(x);
        }
    }

    void pop() {
        if (stack.empty()) return;

        int top = stack.top();
        if (top == min()) {
            minStack.pop();
        }
        stack.pop();
    }

    int top() {
        if (stack.empty()) return -1;
        return stack.top();
    }

    int min() {
        return minStack.empty() ? -1 : minStack.top();
    }
};


#endif //LEETCODE_CPP_Q30_H
