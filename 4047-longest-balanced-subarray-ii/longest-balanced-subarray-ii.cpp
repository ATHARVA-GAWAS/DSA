class Solution {
public:

vector<int> segMin, segMax, lazy; 

// Function to propagate lazy updates down the tree
void propagate(int i, int l, int r) {
    if (lazy[i] != 0) {
        segMin[i] += lazy[i];
        segMax[i] += lazy[i];

        if (l != r) { // not a leaf node
            lazy[2*i + 1] += lazy[i];
            lazy[2*i + 2] += lazy[i];
        }
        
        lazy[i] = 0;
    }
}

// Function to build segment tree initially with zeros
void build(int i, int l, int r) {
    if (l == r) {
        segMin[i] = 0;
        segMax[i] = 0;
        lazy[i] = 0;
        return;
    }
    int mid = (l + r) / 2;

    build(2*i + 1, l, mid);
    build(2*i + 2, mid + 1, r);

    segMin[i] = min(segMin[2*i + 1], segMin[2*i + 2]);
    segMax[i] = max(segMax[2*i + 1], segMax[2*i + 2]);
    lazy[i] = 0;
}

// Range update: add 'val' to all elements in range [ql, qr]
void updateRange(int i, int l, int r, int ql, int qr, int val) {
    propagate(i, l, r);

    if (qr < l || ql > r) return; // no overlap

    if (ql <= l && r <= qr) {
        lazy[i] += val;
        propagate(i, l, r);
        return;
    }

    int mid = (l + r) / 2;

    updateRange(2*i + 1, l, mid, ql, qr, val);
    updateRange(2*i + 2, mid + 1, r, ql, qr, val);

    segMin[i] = min(segMin[2*i + 1], segMin[2*i + 2]);
    segMax[i] = max(segMax[2*i + 1], segMax[2*i + 2]);
}


int findLeftmostZero(int i, int l, int r) {
    propagate(i, l, r);
    // If no zero possible in this segment
    if (segMin[i] > 0 || segMax[i] < 0) return -1;

    if (l == r) { // leaf node, value must be zero
        return l;
    }
    int mid = (l + r) / 2;

    int leftResult = findLeftmostZero(2*i + 1, l, mid);

    if (leftResult != -1) return leftResult;

    return findLeftmostZero(2*i + 2, mid + 1, r);
}

int longestBalanced(const vector<int>& nums) {
    int N=nums.size();
    // Initialize segment tree arrays to size 4*N
    segMin.assign(4*N, INT_MAX);
    segMax.assign(4*N, INT_MIN);
    lazy.assign(4*N, 0);

    build(0, 0, N-1);

    unordered_map<int, int> lastOccurrence;
    int maxLength = 0;

    for (int r = 0; r < N; ++r) {
        int val = (nums[r] % 2 == 0) ? +1 : -1; // +1 for even, -1 for odd

        int prevIdx = -1;
        if (lastOccurrence.count(nums[r])) {
            prevIdx = lastOccurrence[nums[r]];
            // Remove previous addition for this element's old position
            updateRange(0, 0, N-1, 0, prevIdx, -val);
        }

        // Add current value to range [0, r]
        updateRange(0, 0, N-1, 0, r, val);

        lastOccurrence[nums[r]] = r;

        // Find leftmost zero index in cumulative sum
        int leftZero = findLeftmostZero(0, 0, N-1);

        if (leftZero != -1) {
            int length = r - leftZero + 1;
            maxLength = max(maxLength, length);
        }
    }

    return maxLength;
}

};