/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* Prev = nullptr;
        ListNode* Target = head;
        ListNode* Cur = head;
        
        for (int i = 0; i < n; ++i)
        {
            Cur = Cur->next;
        }

        while (Cur)
        {
            Cur = Cur->next;
            Prev = Target;
            Target = Target->next;
        }

        if (Target == head)
        {
            head = Target->next;
        }
        else
        {
            Prev->next = Target->next;
        }
        delete Target;

        return head;
    }
};
// @lc code=end

