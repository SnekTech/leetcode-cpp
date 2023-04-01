//
// Created by syf on 2023/3/20.
//

#ifndef LEETCODE_CPP_Q206_H
#define LEETCODE_CPP_Q206_H

#include "Common.h"

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode dummy(-1);
        auto p = head;
        while (p != nullptr)
        {
            auto nextP = p->next;
            p->next = dummy.next;
            dummy.next = p;
            p = nextP;
        }

        return dummy.next;
    }
};

#endif //LEETCODE_CPP_Q206_H
