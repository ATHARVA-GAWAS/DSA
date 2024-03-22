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
    bool isPalindrome(ListNode* head) {
        vector<int> a;
        stack<int> st;
        while(head){
            a.push_back(head->val);
            st.push(head->val);
            head=head->next;
        }

        for(int it: a){
            int x=st.top();
            st.pop();
            if(it!=x){
                return false;
            }
        }
        return true;
    }
};