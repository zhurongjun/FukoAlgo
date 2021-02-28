/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        int64_t Reverse = 0;
        int64_t Source = x;

        while (Source > Reverse && x)
        {
            Reverse = Reverse * 10 + x % 10;
            x /= 10;
        }

        return Reverse == Source;
    }
};
// @lc code=end

