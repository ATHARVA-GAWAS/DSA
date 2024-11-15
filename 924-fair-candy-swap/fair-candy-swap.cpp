class Solution {
private:
    bool binarySearch(vector<int>& arr, int target) {
        int left = 0, right = arr.size() - 1;
        while (left <= right) {
            int mid = left + ((right - left) / 2);
            if (arr[mid] == target) {
                return true;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int suma = 0, sumb = 0;
        for (int num : aliceSizes) {
            suma += num;
        }
        for (int num : bobSizes) {
            sumb += num;
        }
        int delta = (sumb-suma)/2;
        sort(bobSizes.begin(), bobSizes.end());
        for (int num : aliceSizes) {
            if (binarySearch(bobSizes, (num + delta))) {
                return {num, num + delta};
            }
        }
        return {};
    }
};