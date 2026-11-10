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
    ListNode* reverse(ListNode* start,ListNode* end)
    {
        ListNode* curr=start;
        ListNode* prev=NULL;
        while(curr!=end)
        {
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL)
           return head;

        ListNode* start=head;//start node
        ListNode* end=head;//end node

        for(int i=0;i<k;i++)
        {
            if(end==NULL)
               return start;//return start node (no reversal)
            end=end->next;
        }
        ListNode* newHead=reverse(start,end);//reverse the node
        head->next=reverseKGroup(end,k);//attach it to end of the reverses list
        return newHead;
    }
};