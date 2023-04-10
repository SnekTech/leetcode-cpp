//
// Created by syf on 2023/4/10.
//
#pragma once

#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMax(n, 0);
        vector<int> rightMax(n, 0);
        leftMax[n - 1] = height[n - 1];
        rightMax[0] = height[0];

        for (int i = n - 2; i >= 0; i--)
            leftMax[i] = max(leftMax[i + 1], height[i]);
        for (int i = 1; i < n; i++)
            rightMax[i] = max(rightMax[i - 1], height[i]);

        int water = 0;
        for (int i = 0; i < n; i++)
        {
            int h = min(leftMax[i], rightMax[i]);
            water += h - height[i];
        }

        return water;
    }
};