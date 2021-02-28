/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
// @lc code=start
#include <unordered_map>
#include <unordered_set>
#include <vector>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> ResultMap;
        std::vector<int> Ret;

        for (int i = 0; i < nums.size(); ++i)
        {
            ResultMap[target - nums[i]] = i;
        }
        
        for (int i = 0; i < nums.size(); ++i)
        {
            auto It = ResultMap.find(nums[i]);
            if (It != ResultMap.end() && It->second != i)
            {
                Ret.emplace_back(i);
                Ret.emplace_back(It->second);
                break;
            }
        }

        return Ret;
    }
};
// @lc code=end

