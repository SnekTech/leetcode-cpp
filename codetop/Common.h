//
// Created by syf on 2023/3/15.
//

#ifndef LEETCODE_CPP_COMMON_H
#define LEETCODE_CPP_COMMON_H

#include <iostream>
#include <vector>
#include <memory>

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

    static ListNode* From(std::vector<int> nums)
    {
        ListNode dummy(-1);
        ListNode* prev = &dummy;
        for (int x : nums)
        {
            prev->next = new ListNode(x);
            prev = prev->next;
        }
        return dummy.next;
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

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
{
    os << "[ ";
    for (const auto& elem : v)
    {
        os << elem << " ";
    }
    os << "]";

    return os;
}

#endif //LEETCODE_CPP_COMMON_H
