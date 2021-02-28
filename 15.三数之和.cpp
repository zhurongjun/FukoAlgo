/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> Ret;
        
        std::sort(nums.begin(), nums.end());

        if (nums.size() < 3) return Ret;

        for (int i = 0; i + 2 < nums.size(); ++i)
        {
            int Left = i + 1;
            int Right = nums.size() - 1;
            int Num1 = nums[i];

            if (Num1 > 0)
            {
                break;
            }

            if (i != 0 && nums[i - 1] == Num1)
            {
                continue;
            }

            while (Left < Right)
            {
                int NumL = nums[Left];
                int NumR = nums[Right];

                if (NumL + NumR + Num1 > 0)
                {
                    --Right;
                }
                else if (NumL + NumR + Num1 < 0)
                {
                    ++Left;
                }
                else
                {
                    Ret.emplace_back(vector<int>{ Num1, NumL, NumR });
                    while (nums[Left] == NumL && Left < Right) ++Left;
                    while (nums[Right] == NumR && Left < Right) --Right;
                }
            }
        }

        return Ret;
    }
};
// @lc code=end

