class Solution
{
public:

    long long getClockwiseDistanceFromBottomLeft(int x,
                                                 int y,
                                                 int side)
    {
        if (x == 0) { // left side of square
            return y;
        } else if (y == side) { // top side of square
            return side + x;
        } else if (x == side) { // right side of square
            return 3LL * side - y;
        }
        // bottom side of square
        return 4LL * side - x;
    }

    int maxDistance(int side, std::vector<std::vector<int>> &points, int k)
    {
        auto n = points.size();
        std::vector<long long> clockwiseDistances(n);
        for (int i = 0; auto point : points) {
            int x = point[0];
            int y = point[1];
            clockwiseDistances[i++] = getClockwiseDistanceFromBottomLeft(x,
                                                                         y,
                                                                         side);
        }
        std::sort(std::begin(clockwiseDistances),
                  std::end(clockwiseDistances));

        for (int i = 0; i < n; ++i) {
            clockwiseDistances.push_back(4LL * side + clockwiseDistances[i]);
        }

        int low = 0;
        int high = 2 * side;
        int maxMinDistance = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int maxCount = 0;
            for (int i = 0; maxCount < k && i < n; ++i) {
                int count{ 0 };
                // start at the ith point
                auto itBegin = std::begin(clockwiseDistances) + i;
                auto itEnd = itBegin + n + 1;
                auto it = itBegin;
                while (count < k) {
                    auto target = *it + mid;
                    it = std::lower_bound(it,
                                          itEnd,
                                          target);
                    if (it != itEnd) {
                        ++count;
                    } else {
                        break;
                    }
                }
                maxCount = std::max(maxCount, count);
            }

            if (maxCount >= k) {
                maxMinDistance = std::max(maxMinDistance, mid);
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return maxMinDistance;
    }
};