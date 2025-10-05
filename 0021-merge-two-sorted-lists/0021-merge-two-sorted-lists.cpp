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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp=list1;
        vector<int>v;
        ListNode* t=list2;
        ListNode* res=NULL;
        while(t!=NULL)
        {
          v.push_back(t->val);
          t=t->next;
        }
        while(temp!=NULL)
        {
          v.push_back(temp->val);
          temp=temp->next;
        }
        sort(v.begin(),v.end());
        for(int  i=v.size()-1;i>=0;i--)
        {
            ListNode* r=new ListNode(v[i],res);
            res=r;
        }
        return res;
    }
};