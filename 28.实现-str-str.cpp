/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start 
class Solution {
public:
    int Sol_KMP_DP_Like(const string& haystack, const string& needle) {
        if (needle.length() == 0) return 0;
        std::vector<vector<int>> DP(needle.length(), vector<int>(256, 0));

        // build dp 
        int DPIndex = 0;
        DP[0][needle[0]] = 1;
        for (int i = 1; i < needle.length(); ++i)
        {
            for (int j = 0; j < 256; ++j)
            {
                DP[i][j] = 
                    needle[i] == j ? 
                    i + 1 : 
                    DP[DPIndex][j];
            }
            DPIndex = DP[DPIndex][needle[i]];
        }

        // search 
        DPIndex = 0;
        for (int i = 0; i < haystack.length(); ++i)
        {
            DPIndex = DP[DPIndex][haystack[i]];

            if (DPIndex == needle.length())
            {
                return i - needle.length() + 1;
            }
        }

        return -1;
    }

    int Sol_KMP(const string& haystack, const string& needle)
    {
        if (needle.length() == 0) return 0;
        std::vector<int> Next(needle.length(), -1);

        // build next array 
        int Index = -1;
        for (int i = 1; i < needle.length(); ++i)
        {
            if (Index == -1)
            {
                Index = Next[i] = needle[i] == needle[0] ? 0 : -1;
            }
            else if (needle[i] == needle[Index + 1])
            {
                Index = Next[i] = Index + 1;
            }
            else
            {
                Index = Next[i] = Next[Index];
                --i;
            }
        }

        // search 
        Index = 0;
        for (int i = 0; i < haystack.length(); ++i)
        {
            if (haystack[i] == needle[Index])
            {
                ++Index;
            }
            else if (Index != 0)
            {
                Index = Next[Index - 1] + 1;
                --i;
            }
            
            if (Index == needle.length())
            {
                return i - needle.length() + 1;
            }
        }

        return -1;
    }


    int strStr(string haystack, string needle)
    {
        // return Sol_KMP_DP_Like(haystack, needle);
        return Sol_KMP(haystack, needle);
    }
};
// @lc code=end

