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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res =NULL;
        int sum,carry=0;
        while(l1!=NULL || l2!=NULL)
        {
            int p=(l1!=NULL)?l1->val:0;
            int q=(l2!=NULL)?l2->val:0;
            sum=p+q+carry;
            carry=sum/10;
            sum=sum%10;
            ListNode* r=new ListNode(sum,res);
            res=r;
            if(l1)
            l1=l1->next;
            if(l2)
            l2=l2->next;
        }
        while(carry!=0)
        {
          sum=carry%10;
          ListNode* r=new ListNode(sum,res);
          carry/=10;
          res=r;
        }
        ListNode*t=NULL;
        ListNode*c=res;
        while(c!=NULL)
        {
            ListNode* r=c->next;
            c->next=t;
            t=c;
            c=r;
        }
        return t;
    }
};