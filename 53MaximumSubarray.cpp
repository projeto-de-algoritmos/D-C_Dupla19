#include <bits/stdc++.h>

/*
    Problem: https://leetcode.com/problems/maximum-subarray/
    Author: Maicon Mares
*/

class Solution
{
public:
    int greatest(int a, int b)
    {
        return (a > b) ? a : b;
    }

    int greatest(int a, int b, int c)
    {
        return greatest(greatest(a, b), c);
    }

    int maxSum(vector<int> &nums, int l, int m, int r)
    {
        int max_here = 0, left_sum = INT_MIN, right_sum = INT_MIN;

        for (int i = m; i >= l; i--)
        {
            max_here += nums[i];
            if (left_sum < max_here)
                left_sum = max_here;
        }

        max_here = 0;

        for (int j = m + 1; j <= r; j++)
        {
            max_here += nums[j];
            if (right_sum < max_here)
                right_sum = max_here;
        }
        return greatest(left_sum + right_sum, left_sum, right_sum);
    }

    int divideSum(vector<int> &nums, int l, int r)
    {
        if (r <= l)
            return nums[l];

        int middle = (l + r) / 2;

        return greatest(divideSum(nums, l, middle), divideSum(nums, middle + 1, r), maxSum(nums, l, middle, r));
    }

    int maxSubArray(vector<int> &nums)
    {
        return divideSum(nums, 0, nums.size() - 1);
    }
};