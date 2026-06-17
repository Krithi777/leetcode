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
        ListNode dummy(0);
        ListNode* res=&dummy;
        int sum=0,carry=0;
        while(l1!=NULL || l2!=NULL|| carry!=0)
        {
            int p=(l1!=NULL)?l1->val:0;
            int q=(l2!=NULL)?l2->val:0;
            sum=p+q+carry;
            carry=sum/10;
            sum=sum%10;
            res->next=new ListNode(sum);
            res=res->next;
            if(l1)
              l1=l1->next;
            if(l2)
              l2=l2->next;
        }
        return dummy.next;
    }
};