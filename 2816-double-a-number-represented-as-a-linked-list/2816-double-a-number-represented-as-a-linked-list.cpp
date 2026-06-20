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
        if(t->val>=5)
        {
            ListNode* temp=new ListNode(1,t);
            head=temp;
        }
        while(t!=NULL)
        {
            int k=0;
            if(t->next!=NULL && t->next->val>=5)
                k=1;
            k=k+(t->val*2)%10;
            t->val=k;
            t=t->next;
        }
        return head;
    }
};