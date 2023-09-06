class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int length = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            length++;
            curr = curr->next;
        }
        
        int base_size = length / k;
        int extra_size = length % k;
        
        vector<ListNode*> ans;
        curr = head;
        
        for (int i = 0; i < k; i++) {
            ListNode* part_head = curr;
            int part_size;

            if (i < extra_size)      
                part_size = base_size + 1;
            else                
                part_size = base_size;
                        
            for (int j = 0; j < part_size - 1; j++) {
                if (curr != NULL) curr = curr->next;
            }
            
            if (curr != NULL) {
                ListNode* next_node = curr->next;
                curr->next = NULL; 
                curr = next_node;
            }
            ans.push_back(part_head);
        }
        return ans;
    }
};