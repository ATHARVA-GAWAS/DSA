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
    ListNode* doubleIt(ListNode* head) {
        string num = "";
        ListNode* temp = head;

        while(temp != NULL){
            num += ('0' + temp->val);
            temp = temp->next;
        }
        int carry = 0;
        for(int i = num.length() - 1; i >= 0; i--){
            int sum = (num[i] - '0') * 2 + carry;
            carry = sum/10;
            num[i] = ('0' + sum%10);
        }
        if(carry){
            char temp = '0' + carry;
            num = temp + num;
        }
        
        ListNode* newHead = new ListNode(num[0]-'0');
        temp = newHead;

        for(int i = 1; i < num.length(); i++){
            ListNode* newNode = new ListNode(num[i]-'0');
            temp->next = newNode;
            temp = temp->next;
        }

        return newHead;
    }
};