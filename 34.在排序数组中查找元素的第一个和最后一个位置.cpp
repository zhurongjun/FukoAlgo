/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> Ret(2, -1);
        if (!nums.size()) return Ret;

        int Left = 0, Right = nums.size() - 1;
        
        while (Left <= Right)
        {
            int Mid = (Left + Right) / 2;
            int MidNum = nums[Mid];

            if (MidNum == target)
            {
                Left = Right = Mid;

                while (Left >= 0 && nums[Left] == target) --Left;
                while (Right < nums.size() && nums[Right] == target) ++Right;

                Ret[0] = Left + 1;
                Ret[1] = Right - 1;

                return Ret;
            }
            else if (target < MidNum)
            {
                Right = Mid - 1;
            }
            else
            {
                Left = Mid + 1;
            }
        }

        return Ret;
    }
};
// @lc code=end

