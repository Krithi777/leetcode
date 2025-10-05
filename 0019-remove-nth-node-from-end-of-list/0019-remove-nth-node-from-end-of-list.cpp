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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        stack<int> s;
        ListNode* res=NULL;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            s.push(temp->val);
            temp=temp->next;
        }
        int p=0;
        while(!s.empty())
        {
            if(n==1 && p==0)
            {
              s.pop();
              p=1;
              continue;
            }
            ListNode* r=new ListNode(s.top(),res);
            res=r;
            n--;
            s.pop();
        }
        return res;
    }
};