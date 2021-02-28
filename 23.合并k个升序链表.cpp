/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
    ListNode* MergeTwo(ListNode* A, ListNode* B)
    {
        if ((!A) || (!B)) return A ? A : B;
        
        ListNode Head;
        ListNode *Tail = &Head;

        while (A && B)
        {
            if (A->val < B->val) 
            {
                Tail->next = A; 
                A= A->next;
            } 
            else 
            {
                Tail->next = B; 
                B = B->next;
            }
            Tail = Tail->next;
        }
        Tail->next = A ? A : B;
        return Head.next;
    }

    ListNode* Sol_Foreach(vector<ListNode*>& lists) 
    {
        if (lists.size() == 0) return nullptr;
        
        int StartIndex = 0;
        while(!lists[StartIndex])
        {
            ++StartIndex;
            if (StartIndex >= lists.size()) return nullptr;
        }

        ListNode* Ret = lists[StartIndex];

        for (int i = StartIndex + 1; i < lists.size(); ++i)
        {
            Ret = MergeTwo(Ret, lists[i]);
        }

        return Ret;
    }

    ListNode* Partion_Help(vector<ListNode*>& lists, int Left, int Right)
    {
        if (Right - Left < 0) return nullptr;
        if (Right - Left == 0) return lists[Left];
        ListNode* ListA = Partion_Help(lists, Left, (Left + Right) / 2);
        ListNode* ListB = Partion_Help(lists, (Left + Right) / 2 + 1, Right);

        return MergeTwo(ListA, ListB);
    }
    ListNode* Sol_Partion(vector<ListNode*>& lists)
    {
        return Partion_Help(lists, 0, lists.size() - 1);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        // return Sol_Foreach(lists);
        return Sol_Partion(lists);
    }
};
// @lc code=end

