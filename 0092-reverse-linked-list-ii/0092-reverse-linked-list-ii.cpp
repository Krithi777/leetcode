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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right)
          return head;
        ListNode* l=head;
        ListNode* r=head;
        ListNode dummy(0);
        ListNode* a=&dummy;
        ListNode* b=NULL;
        for(int i=0;i<left-1;i++)
        {
           a->next=l;
           a=a->next;
           l=l->next;
        }
        for(int i=0;i<right-1;i++)
            r=r->next;
        b=r->next;
        ListNode* curr=l;
        ListNode* prev=NULL;
        while(curr!=b)
        {
            ListNode* t=curr->next;
            curr->next=prev;
            prev=curr;
            curr=t;
        }
        a->next=prev;
        l->next=b;
        return dummy.next;
    }
};