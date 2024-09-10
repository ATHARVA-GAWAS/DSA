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
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr = head;
        while (curr != nullptr && curr->next != nullptr) {

            int gcdValue = gcd(curr->val, curr->next->val);

            ListNode* newNode = new ListNode(gcdValue);
            
            // Insert new node between curr and curr->next
            newNode->next = curr->next;
            curr->next = newNode;
            
            // Move curr pointer two steps forward
            curr = newNode->next;
        }
        return head;
    }
};