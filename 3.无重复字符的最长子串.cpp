/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const char* Bucket[128] = { nullptr };

        const char* Begin = s.c_str();
        const char* End = s.c_str();
        const char* const StrEnd = s.c_str() + s.length();

        int MaxLen = 0;

        while (End != StrEnd)
        {
            if (Bucket[*End] >= Begin)
            {
                MaxLen = std::max<int>(MaxLen, End - Begin);
                Begin = Bucket[*End] + 1;
            }
            
            Bucket[*End] = End;
            ++End;
        }
        MaxLen = std::max<int>(MaxLen, End - Begin);

        return MaxLen;
    }
};
// @lc code=end

