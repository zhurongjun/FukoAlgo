/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0) return 0;
        if(divisor == 1) return dividend;
        if(divisor == -1)
        {
            if(dividend>INT_MIN) return -dividend;
            return INT_MAX;
        }

        int Sign = 1;
        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))
        {
            Sign = -1;
        }
        
        dividend = dividend < 0 ? dividend : -dividend;
        divisor = divisor < 0 ? divisor : -divisor;

        int Ret = Help(dividend, divisor);

        return Sign * Ret;
    }
    
    int Help(int A, int B)
    {
        if (A > B) return 0;

        int Count = 0;
        int CountStep = 1;
        int Step = B;

        while (Step >= A)
        {
            Count += CountStep;
            A -= Step;

            CountStep += CountStep;
            if (Step >= INT_MIN / 2)
            {
                Step += Step;
            }
            else
            {
                break;
            }
        }

        return Count + Help(A, B);
    }
};
// @lc code=end

