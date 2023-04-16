//
// Created by syf on 2023/4/16.
//
#pragma once
#include <vector>
#include "Common.h"

using namespace std;

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = (int)preorder.size();
        return build(preorder, 0, n - 1, inorder, 0, n - 1);
    }

    TreeNode* build(const vector<int>& pre, int preLeft, int preRight, const vector<int>& in, int inLeft, int inRight)
    {
        if (preLeft > preRight)
            return nullptr;

        auto root = new TreeNode(pre[preLeft]);
        if (preLeft == preRight)
        {
            return root;
        }

        int rootIndex = -1;
        for (int i = inLeft; i <= inRight; i++)
            if (in[i] == root->val)
            {
                rootIndex = i;
                break;
            }

        int leftChildLength = rootIndex - inLeft;
        root->left = build(pre, preLeft + 1, preLeft + leftChildLength, in, inLeft, rootIndex - 1);
        root->right = build(pre, preLeft + leftChildLength + 1, preRight, in, rootIndex + 1, inRight);

        return root;
    }
};