/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (!nums.size()) return 0;

        int Left = 0, Right = nums.size() - 1;

        while (Left <= Right)
        {
            int Mid = (Left + Right) / 2;
            
            if (target == nums[Mid])
            {
                return Mid;
            }
            else if (target < nums[Mid])
            {
                Right = Mid - 1;
            }
            else
            {
                Left = Mid + 1;
            }
        }

        return Left;
    }
};
// @lc code=end

