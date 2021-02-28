/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int Left = 0;
        int Right = height.size() - 1;

        int Max = 0;

        while (Left < Right)
        {
            int NumL = height[Left];
            int NumR = height[Right];
            int Len = Right - Left;

            if (NumL <= NumR)
            {
                Max = std::max(NumL * Len, Max);
                while (height[Left] <= NumL && Left < Right) ++Left;
            }
            else
            {
                Max = std::max(NumR * Len, Max);
                while (height[Right] <= NumR && Left < Right) --Right;
            }
        }

        return Max;
    }
};
// @lc code=end

