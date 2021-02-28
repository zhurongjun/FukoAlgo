/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        if (s.length() == 0) return 0;

        int Ret = 0;
        int BeginIndex = 0;
        bool bIsNegative = false;

        while(s[BeginIndex] == ' ') ++BeginIndex;
        if (s[BeginIndex] == '-')
        {
            bIsNegative = true;
            ++BeginIndex;
        }
        else if (s[BeginIndex] == '+')
        {
            ++BeginIndex;
        }

        for (int i = BeginIndex; i < s.length(); ++i)
        {
            int N = s[i] - '0';
            if (N >= 0 && N <= 9)
            {
                if (bIsNegative)
                {
                    N = -N;
                }
                if (Ret > INT_MAX/10 || (Ret == INT_MAX / 10 && N > 7)) return INT_MAX;
                if (Ret < INT_MIN/10 || (Ret == INT_MIN / 10 && N < -8)) return INT_MIN;
                Ret = Ret * 10 + N;
            }
            else
            {
                break;
            }
        }

        return Ret;
    }
};
// @lc code=end

