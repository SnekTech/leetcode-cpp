//
// Created by syf on 2023/4/16.
//

#pragma once

#include "Common.h"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode dummy(-1);
        auto prev = &dummy;
        auto p1 = list1;
        auto p2 = list2;

        while (p1 != nullptr && p2 != nullptr)
        {
            if (p1->val <= p2->val)
            {
                prev->next = p1;
                p1 = p1->next;
            }
            else
            {
                prev->next = p2;
                p2 = p2->next;
            }
            prev = prev->next;
        }

        if (p1 != nullptr)
        {
            prev->next = p1;
        }
        else if (p2 != nullptr)
        {
            prev->next = p2;
        }

        return dummy.next;
    }
};