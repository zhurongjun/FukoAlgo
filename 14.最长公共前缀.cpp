/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        
        string Ret;
        bool bExit = false;
        int Index = 0;

        while (true)
        {
            char Ch;
            for (int i = 0; i < strs.size(); ++i)
            {
                const string& CurStr = strs[i];
                if (Index >= CurStr.length())
                {
                    bExit = true;
                    break;
                }

                if (i == 0)
                {
                    Ch = CurStr[Index];
                }
                else if (Ch != CurStr[Index])
                {
                    bExit = true;
                    break;
                }
            }

            if (bExit)
            {
                break;
            }
            else
            {
                Ret += Ch;
                ++Index;
            }
        }

        return Ret;
    }  
};
// @lc code=end

