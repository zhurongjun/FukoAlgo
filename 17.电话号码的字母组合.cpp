/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

#include <unordered_map>
#include <string>
// @lc code=start
class Solution {
public:
    inline int Pow(int A, int N)
    {
        if (N == 1) return A;
        int Half = Pow(A ,N / 2);
        Half *= Half;
        return N % 2 ? Half * A : Half;
    }

    vector<string> letterCombinations(string digits) {
        static std::unordered_map<char, std::string> StrDic = 
        {
            {'2', "abc"} ,
            {'3', "def"} ,
            {'4', "ghi"} ,
            {'5', "jkl"} ,
            {'6', "mno"} ,
            {'7', "pqrs"} ,
            {'8', "tuv"} ,
            {'9', "wxyz"} ,
        };

        std::vector<std::string> Ret;
        if (digits.size() == 0) return Ret;
        Ret.reserve(Pow(3, digits.length()));

        for (int i = 0; i < digits.length(); ++i)
        {
            const string& Str = StrDic[digits[i]];
            int RawLen = Ret.size();
            if (RawLen == 0)
            {
                 for (int j = 0; j < Str.length(); ++j)
                {
                    char Ch = Str[j];
                    Ret.emplace_back(std::string(1, Ch));
                    continue;
                }
            }

            for (int j = 1; j < Str.length(); ++j)
            {
                char Ch = Str[j];

                for (int k = 0; k < RawLen; ++k)
                {
                    Ret.emplace_back(Ret[k] + Ch);
                }
            }

            for (int k = 0; k < RawLen; ++k)
            {
                Ret[k] += Str[0];
            }
        }

        return Ret;
    }
};
// @lc code=end

