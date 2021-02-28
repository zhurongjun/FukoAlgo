/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int Ret = 0;
        if (nums.size() == 0) return 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[Ret] == nums[i])
            {
                continue;
            }

            ++Ret;
            nums[Ret] = nums[i];
        }
        
        ++Ret;
        return Ret;
    }
};
// @lc code=end

