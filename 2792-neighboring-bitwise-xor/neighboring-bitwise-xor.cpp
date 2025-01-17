class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n=derived.size();

        int ans=0;

        //since all elements from the original array are used twice, the xor-sum of the derived array should be zero 

        for(int i=0;i<n;i++){
            ans=ans^derived[i];
        }

        return ans==0;
    }
};