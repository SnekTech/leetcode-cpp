//
// Created by syf on 2023/3/15.
//

#ifndef LEETCODE_CPP_LISTNODE_H
#define LEETCODE_CPP_LISTNODE_H

struct ListNode
{
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr)
    {
    }

    ListNode(int x, ListNode* next) : val(x), next(next)
    {
    }
};

#endif //LEETCODE_CPP_LISTNODE_H
