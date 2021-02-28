/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) return;

        int Target = nums.size() - 2;

        while (Target >= 0 && nums[Target] >= nums[Target + 1]) --Target;

        if (Target >= 0)
        {
            int SwapTarget = nums.size() - 1;

            while(SwapTarget >= 0 && nums[Target] >= nums[SwapTarget]) --SwapTarget;

            std::swap(nums[Target], nums[SwapTarget]);
        }

        std::reverse(nums.begin() + (Target + 1), nums.end());
    }
};
// @lc code=end

