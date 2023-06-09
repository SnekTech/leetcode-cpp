//
// Created by syf on 2023/3/15.
//

#ifndef LEETCODE_CPP_Q24_H
#define LEETCODE_CPP_Q24_H

#include "ListNode.h"

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        auto dummy = ListNode(-1);

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

#endif //LEETCODE_CPP_Q24_H
