class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
       auto compare = [](const string& a, const string& b) {
            if (a.size() == b.size()) {
                return a > b;  
            }
            return a.size() > b.size();  
        };
        
        priority_queue<string, vector<string>, decltype(compare)> pq(compare);
        

        for (const string& num : nums) {
            pq.push(num);
            if (pq.size() > k) {
                pq.pop();  
            }
        }
        
        return pq.top();
    }
};