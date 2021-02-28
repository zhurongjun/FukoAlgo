/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> Ret;

        int Len = nums.size();

        if (Len < 4) return Ret;

        std::sort(nums.begin(), nums.end());

        for (int i = 0; i + 3 < nums.size(); ++i)
        {
            int Num1 = nums[i];

            if (i != 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            if (Num1 + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
            {
                break;
            }

            if (Num1 + nums[Len - 1] + nums[Len - 2] + nums[Len - 3] < target)
            {
                continue;
            }

            for (int j = i + 1; j + 2 < nums.size(); ++j)
            {
                int Num2 = nums[j];

                if (j != i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }

                if (Num1 + Num2 + nums[j + 1] + nums[j + 2] > target)
                {
                    break;
                }

                if (Num1 + Num2 + nums[Len - 1] + nums[Len - 2] < target)
                {
                    continue;
                }

                int Left = j + 1;
                int Right = Len - 1;

                while (Left < Right)
                {
                    int NumL = nums[Left];
                    int NumR = nums[Right];
                    int CurSum = Num1 + Num2 + NumL + NumR;

                    if (CurSum > target)
                    {
                        --Right;
                    }
                    else if (CurSum < target)
                    {
                        ++Left;
                    }
                    else
                    {
                        Ret.emplace_back(vector<int>{ Num1, Num2, NumL, NumR });
                        while (nums[Left] == NumL && Left < Right) ++Left;
                        while (nums[Right] == NumR && Left < Right) --Right;
                    }
                }
            }
        }

        return Ret;
    }
};
// @lc code=end

