class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        int m=bank[0].size();
        
        vector<int> ones;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<m;j++){
              if(bank[i][j]=='1'){
                  cnt++;
              }
            }
            if(cnt!=0){
                ones.push_back(cnt);
            }
        }
        if(ones.size()==0){
            return 0;
        }
        int ans=0;
        for(int i=0;i<ones.size()-1;i++){
            ans+=ones[i]*ones[i+1];
        }
        return ans;
    }
};