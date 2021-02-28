/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
#include <string>
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        
        int StrLen = s.length();
        int T = numRows * 2 - 2;

        std::string Ret;
        Ret.reserve(StrLen);

        for (int i = 0; i < numRows; ++i)
        {
            for (int j = i; j < StrLen; j += T)
            {
                Ret += s[j];

                int NextIndex = j + T - i * 2;
                if (i !=0 && i != numRows - 1 && NextIndex < StrLen)
                {
                    Ret += s[NextIndex];
                }
            }
        }

        return Ret;
    }
};
// @lc code=end

