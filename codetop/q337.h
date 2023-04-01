//
// Created by syf on 2023/4/1.
//

#ifndef LEETCODE_CPP_Q337_H
#define LEETCODE_CPP_Q337_H

#include <unordered_map>
#include "Common.h"

using namespace std;

class Solution {
public:
    unordered_map<TreeNode*, int> memoInclude;
    unordered_map<TreeNode*, int> memoNotInclude;
    int rob(TreeNode* root) {
        dfs(root);
        return max(memoInclude[root], memoNotInclude[root]);
    }

    void dfs(TreeNode* root)
    {
        if (root == nullptr)
            return;

        rob(root->left);
        rob(root->right);
        memoInclude[root] = root->val + memoNotInclude[root->left] + memoNotInclude[root->right];
        memoNotInclude[root] = max(memoInclude[root->left], memoNotInclude[root->left]) + max(memoInclude[root->right], memoNotInclude[root->right]);
    }
};
#endif //LEETCODE_CPP_Q337_H
