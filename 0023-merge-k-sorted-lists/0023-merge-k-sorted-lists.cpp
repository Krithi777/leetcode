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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(0);
        ListNode* res=&dummy;
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>p;
        for(int i=0;i<lists.size();i++)
        {
            ListNode* t=lists[i];
            if(t!=NULL)
             p.push({t->val,t});
        }
        while(p.size()>0)
        {
            ListNode* temp=p.top().second->next;
            res->next=p.top().second;
            res=res->next;
            p.pop();
            if(temp!=NULL)
              p.push({temp->val,temp});        
        }
        res->next=NULL;
        return dummy.next;
    }
};