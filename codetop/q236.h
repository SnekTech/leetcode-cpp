//
// Created by syf on 2023/4/7.
//
#pragma once

#include "Common.h"

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return nullptr;
        if (root == p)
            return p;
        if (root == q)
            return q;

        auto tryLeft = lowestCommonAncestor(root->left, p, q);
        auto tryRight = lowestCommonAncestor(root->right, p, q);
        if (tryLeft && tryRight)
            return root;

        return tryLeft ? tryLeft : tryRight;
    }
};