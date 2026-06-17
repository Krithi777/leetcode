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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* slow=head;
        ListNode* fast=head;
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* h=head;
        int count=0;
        while(h!=NULL)
        {
            h=h->next;
            count++;
        }
        k=k%count;
        if(k==0)
          return head;
        while(k && fast->next)
        {
           fast=fast->next;
           k--;
        }
        while(fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
        ListNode* t=slow->next;
        slow->next=NULL;
        fast->next=head;
        return t;     
    }
};