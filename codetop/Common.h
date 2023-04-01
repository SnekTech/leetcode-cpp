//
// Created by syf on 2023/3/15.
//

#ifndef LEETCODE_CPP_COMMON_H
#define LEETCODE_CPP_COMMON_H

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

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : TreeNode(0)
    {
    }

    TreeNode(int x) : TreeNode(x, nullptr, nullptr)
    {
    }

    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right)
    {
    }
};

#endif //LEETCODE_CPP_COMMON_H
