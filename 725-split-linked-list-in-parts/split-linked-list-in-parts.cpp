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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n=0;

        ListNode *cur=head;

        while(cur){
            n++;
            cur=cur->next;
        }

        vector<ListNode*> ans(k,NULL);
        int sizze=n/k;
        int rem=n%k;

        cur=head;

        for(int i=0;i<k;i++){
            if(!cur){
                break;
            }
            ans[i]=cur;
            int part_size=sizze;
            if(rem>0){
                part_size++;
                rem--;
            }

            for(int j=1;j<part_size;j++){
                cur=cur->next;
            }

            ListNode* nexxt=cur->next;
            cur->next=NULL;
            cur=nexxt;
        }

        return ans;
    }
};