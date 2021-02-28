/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
#include <vector>
class Solution {
public:
    int reverse(int x) {
        int Ret = 0;

        while (x)
        {
            int Pop = x % 10;
            if (Ret > INT_MAX/10 || (Ret == INT_MAX / 10 && Pop > 7)) return 0;
            if (Ret < INT_MIN/10 || (Ret == INT_MIN / 10 && Pop < -8)) return 0;
            x /= 10;
            Ret = Ret * 10 + Pop;
        }

        return Ret;
    }
};
// @lc code=end

