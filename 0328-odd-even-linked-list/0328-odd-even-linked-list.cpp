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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL)
          return head;
        ListNode dummy(0);
        ListNode dummy1(0);
        ListNode* odd=&dummy;
        ListNode* even=&dummy1;
        ListNode* t=head;
        int count=0;
        while(t!=NULL)
        {
            if(count==0)
            {
                odd->next=t;
                t=t->next;
                odd=odd->next;
                count=1;
            }
            else
            {
                even->next=t;
                t=t->next;
                even=even->next;
                count=0;
            }
        }    
        even->next=NULL;
        odd->next=dummy1.next;
        return dummy.next;
    }
};