//
// Created by syf on 2023/4/10.
//
#pragma once

#include "Common.h"

class Solution
{
public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        auto begin = head;
        auto end = head;
        ListNode dummy(-1);
        ListNode* prev = &dummy;
        while (true)
        {
            bool shouldReverse = true;
            for (int i = 0; i < k; i++)
            {
                if (end == nullptr)
                {
                    shouldReverse = false;
                    break;
                }
                end = end->next;
            }

            if (!shouldReverse)
            {
                prev->next = begin;
                break;
            }

            prev->next = reverse(begin, end);
            prev = begin;
            begin = end;
        }

        return dummy.next;
    }

private:
    ListNode* reverse(ListNode* head, ListNode* end)
    {
        ListNode dummy(-1);
        auto p = head;
        while (p != end)
        {
            auto nextP = p->next;
            p->next = dummy.next;
            dummy.next = p;
            p = nextP;
        }
        return dummy.next;
    }
};