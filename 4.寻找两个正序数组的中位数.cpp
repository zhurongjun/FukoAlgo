/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int Len1 = nums1.size();
        int Len2 = nums2.size();

        if (Len1 > Len2)
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        int Left = 0;
        int Right = Len1 * 2;
        int LMax1, LMax2, RMin1, RMin2;

        while (Left <= Right)
        {
            int Cut1 = (Left + Right) / 2;
            int Cut2 = Len1 + Len2 - Cut1;

            LMax1 = (Cut1 == 0) ? INT_MIN : nums1[(Cut1 - 1) / 2];
            RMin1 = (Cut1 == Len1 * 2) ? INT_MAX : nums1[Cut1 / 2];
            LMax2 = (Cut2 == 0) ? INT_MIN : nums2[(Cut2 - 1) / 2];
            RMin2 = (Cut2 == Len2 * 2) ? INT_MAX :nums2[Cut2 / 2];

            if (LMax1 > RMin2)
            {
                Right = Cut1 - 1;
            }
            else if (LMax2 > RMin1)
            {
                Left = Cut1 + 1;
            }
            else
            {
                break;
            }
        }

        return (double(std::max(LMax1, LMax2)) + double(std::min(RMin1, RMin2))) / 2.0;
    }
};
// @lc code=end

