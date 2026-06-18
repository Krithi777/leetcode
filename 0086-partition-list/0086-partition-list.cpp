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
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy(0);
        ListNode dummy1(0);
        ListNode* t=head;
        ListNode* bef=&dummy;
        ListNode* aft=&dummy1;
        while(t!=NULL)
        {
            if(t->val<x)
            {
                bef->next=t;
                t=t->next;
                bef=bef->next;
                bef->next=NULL;
            }
            else
            {
                aft->next=t;
                t=t->next;
                aft=aft->next;
                aft->next=NULL;
            }
        }
        bef->next=dummy1.next;
        return dummy.next;
    }
};