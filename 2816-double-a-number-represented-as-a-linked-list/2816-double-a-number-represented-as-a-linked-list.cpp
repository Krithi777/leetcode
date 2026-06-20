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
    ListNode* doubleIt(ListNode* head) {
        ListNode* t=head;
        ListNode dummy(0);
        ListNode* n=&dummy;
        if(t->val>=5)
        {
            ListNode* temp=new ListNode(1);
            n->next=temp;
            n=n->next;
        }
        while(t!=NULL)
        {
            int k=0;
            if(t->next!=NULL && t->next->val>=5)
                k=1;
            k=k+(t->val*2)%10;
            ListNode* j=new ListNode(k);
            n->next=j;
            n=n->next;
            t=t->next;
        }
        return dummy.next;
    }
};