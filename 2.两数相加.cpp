/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2) return nullptr;

        ListNode* RetNode = new ListNode(0);
        ListNode* CurNode = RetNode;
        int AddNum = 0;

        while(true)
        {
            int Result = 0;
            Result += l1 ? l1->val : 0;
            Result += l2 ? l2->val : 0;
            Result += AddNum;

            CurNode->val = Result % 10;
            AddNum = Result / 10;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;

            if (l1 || l2 || AddNum)
            {
                CurNode->next= new ListNode(0);
                CurNode = CurNode->next;
            }
            else
            {
                return RetNode;
            }
        }
    }
};
// @lc code=end

