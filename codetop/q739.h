//
// Created by syf on 2023/3/30.
//

#ifndef LEETCODE_CPP_Q739_H
#define LEETCODE_CPP_Q739_H
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> minStack;
        int n =(int) temperatures.size();
        vector<int> answer;
        answer.resize(n, 0);

        for (int i = 0; i < n; i++)
        {
            while (!minStack.empty() && temperatures[i] > temperatures[minStack.top()])
            {
                int prevIndex = minStack.top();
                answer[prevIndex] = i - prevIndex;
                minStack.pop();
            }
            minStack.push(i);
        }

        return answer;
    }
};

#endif //LEETCODE_CPP_Q739_H
