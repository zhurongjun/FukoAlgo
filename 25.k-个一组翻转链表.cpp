/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* ReverseN(ListNode* Head, int N)
    {
        ListNode* Temp = Head;
        int Count = 0;
        
        // Count 
        while(Temp->next && Count < N)
        {
            ++Count;
            Temp = Temp->next;
        }
        if (Count < N) return nullptr;

        // Reverse 
        ListNode* NewHead = Head->next;
        ListNode* OldTail = Temp->next;
        Temp = Head->next;

        for (int i = 0; i < N; ++i)
        {
            ListNode* NextNode = Temp->next;
            Temp->next = Head->next;
            Head->next = Temp;
            Temp = NextNode;;
        }

        NewHead->next = OldTail;

        return NewHead;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode Head(0, head);
        
        ListNode* NextHead = &Head;
        while (NextHead)
        {
            NextHead = ReverseN(NextHead, k);
        }

        return Head.next;
    }
};
// @lc code=end

