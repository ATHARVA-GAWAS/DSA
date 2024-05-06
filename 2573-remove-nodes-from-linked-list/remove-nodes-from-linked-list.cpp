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
    int maxi=0;
    ListNode* solve(ListNode *p){
        if(!p){
            return nullptr;
        }

        p->next=solve(p->next);

        maxi=max(maxi,p->val);

        if(p->val<maxi){
            ListNode *temp=p->next;
            p->next=NULL;
            return temp;
        }
        return p;
    }
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode *p=head;
        head=solve(p);
        return head;
    }
};