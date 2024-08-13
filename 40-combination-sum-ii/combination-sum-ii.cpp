class Solution {
    vector<vector<int>> ans;
    vector<int> res;
public:
    void f(int ind, int target, vector<int>& candidates) {
        if (target == 0) {
            ans.push_back(res);
            return;
        }
        
        for (int i = ind; i < candidates.size(); ++i) {

            if (i > ind && candidates[i] == candidates[i - 1]) continue;
            
            if (candidates[i] <= target) {
                res.push_back(candidates[i]);
                f(i + 1, target - candidates[i], candidates); 
                res.pop_back(); // Backtrack
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // Sort to handle duplicates
        f(0, target, candidates);
        return ans;
    }
};
