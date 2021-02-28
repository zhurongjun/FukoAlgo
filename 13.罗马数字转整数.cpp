/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
public:
    inline int GetValue(char Ch)
    {
        switch(Ch)
        {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }

    int romanToInt(string s) {
       int Ret = 0;
       int LastNum = 0;

       for (int i = 0; i < s.length(); ++i)
       {
            int CurNum = GetValue(s[i]);
            Ret += LastNum < CurNum ? -LastNum * 2 + CurNum : CurNum;
            LastNum = CurNum;
       }
       
       return Ret;
    }

};
// @lc code=end

