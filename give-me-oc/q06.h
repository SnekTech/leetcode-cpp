//
// Created by syf on 2023/3/15.
//

#ifndef LEETCODE_CPP_Q06_H
#define LEETCODE_CPP_Q06_H

#include <vector>
#include "ListNode.h"

using namespace std;

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> result;
        f(head, result);
        return result;
    }

    void f(ListNode* head, vector<int>& result)
    {
        if (head == nullptr) return;

        f(head->next, result);
        result.push_back(head->val);
    }
};

#endif //LEETCODE_CPP_Q06_H
