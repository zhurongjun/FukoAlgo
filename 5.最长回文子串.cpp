/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
#include <string>
#include <vector>
class Solution {
public:
    inline std::string Sol_DP(const std::string& Str)
    {
        std::vector<bool> DP1(Str.length(), true);
        std::vector<bool> DP2(Str.length(), false);
        std::string Ret;

        int Start = 0;
        int Len = 1;

        for (int DPLen = 1; DPLen < Str.length(); ++DPLen)
        {
            for (int L = 0; L + DPLen < Str.length(); ++L)
            {
                int R = L + DPLen;
                bool IsPalindrome = false;
                
                if (DPLen == 1)
                {
                    IsPalindrome = DP2[L] = Str[L] == Str[R];
                }
                else if (DPLen % 2)
                {
                    IsPalindrome = DP2[L] = Str[L] == Str[R] && DP2[L + 1];
                }
                else
                {
                    IsPalindrome = DP1[L] = Str[L] == Str[R] && DP1[L + 1];
                }

                if (IsPalindrome && DPLen + 1 > Len)
                {
                    Start = L;
                    Len = DPLen + 1;
                }
            }
        }

        return Str.substr(Start, Len);
    }

    inline std::string Sol_Expend(const std::string& Str)
    {
        auto Expend = [](const std::string& Str, int& Left, int& Right)
        {
            while (Left >= 0 && Right < Str.size() && Str[Left] == Str[Right])
            {
                --Left;
                ++Right;
            }
            ++Left;
            --Right;
        };

        int Start = 0;
        int Len = 1;

        for (int i = 0; i < Str.size(); ++i)
        {
            int Left, Right, ExpendLen;
            
            Left = Right = i;
            Expend(Str, Left, Right);
            ExpendLen = Right - Left + 1;
            if (ExpendLen > Len)
            {
                Start = Left;
                Len = ExpendLen;
            }
            
            Left = i;
            Right = i + 1;
            Expend(Str, Left, Right);
            ExpendLen = Right - Left + 1;
            if (ExpendLen > Len)
            {
                Start = Left;
                Len = ExpendLen;
            }
        }

        return Str.substr(Start, Len);
    }

    string longestPalindrome(string s) 
    {
        // return Sol_DP(s);
        return Sol_Expend(s);
    }
};
// @lc code=end

