/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int Len = nums.size();

        if (!Len) return -1;
        if (Len == 1) return nums[0] == target ? 0 : -1;

        const int LeftNum = nums[0], RightNum = nums[Len - 1];
        int Left = 0, Right = Len - 1;

        while (Left <= Right)
        {
            int Mid = (Left + Right) / 2;
            int MidNum = nums[Mid];

            if (MidNum == target) 
            {
                return Mid;
            }
            else if (target < MidNum)   // left 
            {
                if (MidNum >= LeftNum && target < LeftNum)
                {
                    Left = Mid + 1;
                }
                else
                {
                    Right = Mid - 1;
                }
            }
            else    // right 
            {
                if (MidNum < LeftNum && target > RightNum)
                {
                    Right = Mid - 1;
                }
                else
                {
                    Left = Mid + 1;
                }
            }
        }

        return -1;
    }
};
// @lc code=end

