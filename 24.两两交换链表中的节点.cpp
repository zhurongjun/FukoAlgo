/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode Head;
        ListNode* PrevNode = &Head;
        ListNode* CurNode = head;
        Head.next = head;

        while (CurNode && CurNode->next)
        {
            PrevNode->next = CurNode->next;
            CurNode->next = CurNode->next->next;
            PrevNode->next->next = CurNode;

            CurNode = CurNode->next;
            PrevNode = PrevNode->next->next;
        }

        return Head.next;
    }
};
// @lc code=end

