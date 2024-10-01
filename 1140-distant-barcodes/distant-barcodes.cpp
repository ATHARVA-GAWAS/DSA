class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int,int> mp;

        for(auto it:barcodes){
            mp[it]++;
        }

        priority_queue<pair<int,int>> pq;

        for(auto it:mp){
            auto p=make_pair(it.second,it.first);
            pq.push(p);
        }

        vector<int> ans;

        while(!pq.empty())
        {
            auto temp1=pq.top();
            pq.pop();
            ans.push_back(temp1.second);
            temp1.first-=1;
            if(!pq.empty())
            {
                auto temp2=pq.top();
                pq.pop();
                ans.push_back(temp2.second);
                temp2.first-=1;
                
                if(temp2.first>0)
                {
                    pq.push(temp2);
                }
            }
            if(temp1.first>0)
            {
                pq.push(temp1);
            }
            
        }

        return ans;
    }
};