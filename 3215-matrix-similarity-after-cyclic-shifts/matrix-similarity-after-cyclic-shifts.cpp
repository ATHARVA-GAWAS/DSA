class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        int shift = k % n;

        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {

                int expectedVal;

                if ((i%2) == 1) { // Odd
                    expectedVal = mat[i][(j+shift)%n]; // Right shift logic
                } 

                else { // Even
                    expectedVal = mat[i][(j-shift+n)%n]; // Left shift logic
                }

                if (mat[i][j] != expectedVal){
                    return false;
                }
            }
        }

        return true;
    }
};