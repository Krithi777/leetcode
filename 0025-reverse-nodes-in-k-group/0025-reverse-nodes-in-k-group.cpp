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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL)
           return head;

        ListNode* curr=head;
        ListNode* bval=NULL;//previous reversal end val
        ListNode* aval;//after reversal end val
        ListNode* res;

        int n=0;//count of nodes
        while(curr!=NULL)
        {
            n++;
            curr=curr->next;
        }
        
        curr=head;
        int times=n/k;
        for(int i=0;i<times;i++)
        {
            int j=k;
            ListNode* prev=NULL;
            aval=curr;
            while(curr!=NULL && j)
            {
                ListNode* temp=curr->next;
                curr->next=prev;
                prev=curr;
                curr=temp;
                j--;
            }
            if(i==0)
              res=prev;
            if(i!=0)
            bval->next=prev;
            bval=aval;     
        }
        aval->next=curr;
        return res;
    }
};