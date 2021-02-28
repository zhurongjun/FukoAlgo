/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        int SLen = s.length();
        int PLen = p.length();

        vector<bool> DP(PLen + 1, false);
        vector<bool> CurDP(PLen + 1, false);
        DP[0] = true;

        for (int i = 0; i <= SLen; ++i)
        {
            CurDP[0] = i == 0;
            for (int j = 1; j <= PLen; ++j)
            {
                char Ch = p[j - 1];

                if (Ch == '*')
                {
                    CurDP[j] = CurDP[j - 2];
                    
                    if (i != 0 && (p[j - 2] == '.' || p[j - 2] == s[i - 1]))
                    {
                        CurDP[j] = CurDP[j] || DP[j];
                    }
                }
                else if (Ch == '.')
                {
                    CurDP[j] = i == 0 ? false : DP[j - 1];
                }
                else
                {
                    CurDP[j] = i == 0 ? false : s[i - 1] == Ch && DP[j - 1];
                }

            }
            std::swap(DP, CurDP);
        }

        return DP[PLen];
    }
};
// @lc code=end

