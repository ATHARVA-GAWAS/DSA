class Solution {
    struct comparator{
        bool operator()(int &a, int &b){
            return a<b;
        }
    };
public:
    int maxProduct(vector<int>& nums) {
         priority_queue<int,vector<int>,comparator>pq;
         for(int i=0;i<nums.size();i++){
             pq.push(nums[i]);
         }
         int ans = pq.top();
         pq.pop();
         int res = pq.top();
         return (ans-1)*(res-1);     
    }
};