class Solution {
public:
    int partitionString(string s) {
        int ans=0;
        set<int> partition;

        for(int i=0;i<s.size();i++){
             if(partition.find(s[i]) != partition.end()){
                ans++;
                partition.clear();
            }
            partition.insert(s[i]);
        }
        return ans+1;
    }
};