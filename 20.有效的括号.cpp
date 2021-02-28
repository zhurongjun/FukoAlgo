/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
#include <vector>
// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        std::vector<char> ChStack;

        for (int i = 0; i < s.length(); ++i)
        {
            char Ch = s[i];
            if (Ch == ')' || Ch == ']' || Ch =='}')
            {
                if (ChStack.size() == 0 || ChStack.back() != Ch)
                {
                    return false;
                }
                ChStack.pop_back();
            }
            else
            {
                switch(Ch)
                {
                case '(':
                    ChStack.emplace_back(')');
                    break;
                case '[':
                    ChStack.emplace_back(']');
                    break;
                case '{':
                    ChStack.emplace_back('}');
                    break;
                }
            }
        }

        return ChStack.size() == 0;
    }
};
// @lc code=end

