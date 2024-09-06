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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st;

        for(auto it:nums){
            st.insert(it);
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy; 
        ListNode* cur = head;

        while(cur){
            if(st.find(cur->val)!=st.end()){
                prev->next = cur->next;
                delete cur;;
            }else{
                prev=cur;
            }
            cur=prev->next;
        }

        head = dummy->next; 
        delete dummy;

        return head;
    }
};