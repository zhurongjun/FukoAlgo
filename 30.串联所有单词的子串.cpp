/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */
#include <unordered_map>
#include <string>
// @lc code=start
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> Ret;
        
        if (!words.size() || !s.length()) return Ret;
        
        int WordLen = words[0].length();
        int WordCount = words.size();

        // build word map 
        std::unordered_map<string, int> WordMap;
        for (int i = 0; i < words.size(); ++i)
        {
            ++WordMap[words[i]];
        }
        
        // each word 
        std::unordered_map<string, int> TempMap;
        std::string Str, TempStr;
        for (int i = 0; i < WordLen; ++i)
        {
            int Left = i, Right = i, TotalCount = 0;
            TempMap.clear();

            while (Right + WordLen <= s.length())
            {
                Str.assign(s.c_str() + Right, WordLen);
                auto It = WordMap.find(Str);

                if (It == WordMap.end())
                {
                    Left = Right + WordLen;
                    TotalCount = 0;
                    for (auto& [key,value] : TempMap)
                    {
                        value = 0;
                    }
                }
                else
                {
                    int& Count = TempMap[Str];
                    ++Count;
                    ++TotalCount;

                    while (Count > It->second)
                    {
                        TempStr.assign(s.c_str() + Left, WordLen);
                        --TempMap[TempStr];
                        --TotalCount;
                        Left += WordLen; 
                    }
                }
                
                if (TotalCount == words.size())
                {
                    Ret.emplace_back(Left);
                }

                Right += WordLen;
            }
        }

        return Ret;
    }
};
// @lc code=end

