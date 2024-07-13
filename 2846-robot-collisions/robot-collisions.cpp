class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> indices(n);
        
        for(int i=0;i<n;i++){
            indices[i]=i;
        }
        stack<int> st;

        auto lambda = [&](int i, int j) {
            return positions[i] < positions[j];
        };

        sort(begin(indices), end(indices), lambda);

        vector<int> result;
        for (int currInd : indices) {
            if (directions[currInd] == 'R') {
                st.push(currInd);
            } 
            else {
                while (!st.empty() && healths[currInd] > 0) {
                    int topIndex = st.top();
                    st.pop();

                    if (healths[topIndex] > healths[currInd]) {
                        healths[topIndex] -= 1;
                        healths[currInd] = 0;
                        st.push(topIndex);
                    } 
                    else if (healths[topIndex] < healths[currInd]) {
                        healths[currInd] -= 1;
                        healths[topIndex] = 0;
                    } 
                    else {
                        healths[currInd] = 0;
                        healths[topIndex] = 0;
                    }
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (healths[i] > 0) {
                result.push_back(healths[i]);
            }
        }
        return result;
    }
};