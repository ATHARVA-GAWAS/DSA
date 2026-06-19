class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int highest = 0;
        int altitude = 0;

        for (int gain_val : gain) {
            altitude += gain_val;
            highest = max(highest, altitude);
        }

        return highest;
    }
};