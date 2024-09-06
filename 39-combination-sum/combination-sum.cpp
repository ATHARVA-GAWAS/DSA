class Solution {
        void f(int ind,int target,vector<int> &arr,vector<vector<int>> &ans, vector<int> &temp){
        if(ind==arr.size()){
            if(target==0){
                ans.push_back(temp);
            }
            return;
        }
        //pick up the element
        if(arr[ind]<=target){
            temp.push_back(arr[ind]);
            f(ind,target-arr[ind],arr,ans,temp); //we can pick multiple so ind is not increased
            temp.pop_back();
        }
        //not pick
        f(ind+1,target,arr,ans,temp);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        f(0,target,candidates,ans,temp);
        return ans;
    }
};