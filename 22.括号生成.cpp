/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */
#include <string>
// @lc code=start
class Solution {
public:
    std::string Str;

    void Help(vector<string>& Results, int LCount, int Level)
    {
        if (Level == 0)
        {
            if (LCount == 0) Results.emplace_back(Str);
            return;
        }

        if (LCount > Level)
        {
            return;
        }

        if (LCount == 0)
        {
            Str += '(';
            Help(Results, 1, Level - 1);
            Str.pop_back();
        }
        else
        {
            Str += ')';
            Help(Results, LCount - 1, Level - 1);
            Str.pop_back();

            Str += '(';
            Help(Results, LCount + 1, Level - 1);
            Str.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> Ret;
        Help(Ret, 0, n * 2);
        return Ret;
    }
};
// @lc code=end

