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
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* curr=slow->next;
        ListNode* prev=NULL;
        slow->next=NULL;
        while(curr!=NULL)
        {
            ListNode* t=curr->next;
            curr->next=prev;
            prev=curr;
            curr=t;
        }
        ListNode* t=head;
        ListNode* s=prev;
        while(t!=NULL && s!=NULL)
        {
            ListNode* p=t->next;
            ListNode* q=s->next;
            t->next=s;
            t->next->next=p;
            t=t->next->next;
            s=q;
        }
    }
};