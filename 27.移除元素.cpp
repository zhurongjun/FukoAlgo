/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int Left = 0, Right = 0;

        while (Right < nums.size())
        {
            if (nums[Right] == val)
            {
                ++Right;
            }
            else
            {
                if (Left != Right)
                {
                    nums[Left] = nums[Right];
                }

                ++Left;
                ++Right;
            }
        }

        return Left;
    }
};
// @lc code=end

