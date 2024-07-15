class Solution {
public:
    bool isposs(vector<int>& a, int h, int mid) {
        int hour = 0;
        for (int i = 0; i < a.size(); i++) {
            hour += (a[i] + mid - 1) / mid; 
            if (hour > h)  
                return false;
        }
        return hour <= h;
    }

    int minEatingSpeed(vector<int>& piles, int H) {
        int l = 1, h = 1e9;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (isposs(piles, H, mid))
                h = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }
};