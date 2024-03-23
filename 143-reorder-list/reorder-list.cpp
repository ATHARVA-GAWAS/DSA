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
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* mid=slow->next;
        ListNode* cur=head;
        ListNode* prev=NULL;
        ListNode* nexxt;

        while(mid){
           nexxt= mid->next;
           mid->next=prev;
           prev=mid;
           mid=nexxt;
        }
        slow->next=NULL;

        ListNode *x=head;
        ListNode *y=prev;

        while(x && y){
            ListNode *x_next=x->next;
            ListNode *y_next=y->next;

            x->next=y;
            y->next=x_next;

            x=x_next;
            y=y_next;
        }
    }
};