class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> pos,neg,ans;
        for(int it:nums){
            if(it>0){
                pos.push_back(it);
            }
            else{
                neg.push_back(it);
            }
        }
        
        for(int i=0;i<pos.size();i++){
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
        }
        return ans;
    }
};