#define ll long long int 
class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) 
    {
        int n = nums.size();

        if(n == 1)  return 0;

        vector<ll> arr(nums.begin(),nums.end());

        int sorted = 0;
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,
        greater<pair<ll,ll>>> pq;


        for(int i = 0; i < n - 1; i++)
        {
            if(arr[i+1] >= arr[i])
                sorted++;

            pq.push({arr[i] + arr[i+1],i});

        }

        if(sorted == n - 1)
            return 0;

        vector<ll> prev(n), next(n);

        for(int i = 0; i < n; i++)
        {
            prev[i] = i - 1;
            next[i] = i + 1;

        }

        int remaining = n;

        vector<bool> removed(n,false);

        while(remaining > 1)
        {
            auto [sum,left] = pq.top();
            pq.pop();

            int right = next[left];

            // skip case 
            if(right == n || removed[left] == true 
            || removed[right] == true || arr[left] + arr[right] != sum)
                continue;

            int pre = prev[left];
            int nxt = next[right];

            if(arr[left] <= arr[right])
                sorted--;

            if(pre != -1 && arr[pre] <= arr[left])
                sorted--;

            if(nxt != n && arr[right] <= arr[nxt])
                sorted--;

            arr[left] += arr[right];
            removed[right] = true;
            remaining--;

            

            if(pre == -1)
                prev[left] = -1;
            else  
            {
                pq.push({arr[pre] + arr[left],pre});
                if(arr[pre] <= arr[left])
                    sorted++;
            }

            if(nxt == n)
                next[left] = n;
            else  
            {
                prev[nxt] = left;
                next[left] = nxt;
                pq.push({arr[left] + arr[nxt],left});
                if(arr[left] <= arr[nxt])
                    sorted++;
            } 

            if(sorted == remaining - 1)
                return n - remaining;
        }

        return n;
        
    }
};