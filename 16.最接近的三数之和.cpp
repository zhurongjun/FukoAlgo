/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution {
public:
    inline int Abs(int N) { return N > 0 ? N : -N; }

    int threeSumClosest(vector<int>& nums, int target) {
        int ClosestNum = INT_MAX;
        int ClosestDis = INT_MAX;

        std::sort(nums.begin(), nums.end());

        for (int i = 0; i + 2 < nums.size(); ++i)
        {
            int NumTarget = nums[i] - target;
            int Left = i + 1;
            int Right = nums.size() - 1;

            if (i != 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            while (Left < Right)
            {
                int NumL = nums[Left];
                int NumR = nums[Right];
                int Distance = NumTarget + NumL + NumR;

                if (Abs(Distance) < ClosestDis)
                {
                    ClosestDis = Abs(Distance);
                    ClosestNum = nums[i] + NumL + NumR;
                }

                if (Distance > 0)
                {
                    --Right;
                }
                else if (Distance < 0)
                {
                    ++Left;
                }
                else
                {
                    return target;
                }
            }
        }

        return ClosestNum;
    }
};
// @lc code=end

