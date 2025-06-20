class Solution {
public:
    int maxDistance(string s, int k) {
        int n=s.size();

        int ans=0;

        int north=0,south=0,west=0,east=0;

        for(int i=0;i<n;i++){
            if(s[i]=='N'){
                north++;
            }
            if(s[i]=='S'){
                south++;
            }
            if(s[i]=='E'){
                east++;
            }
            if(s[i]=='W'){
                west++;
            }

            int x=abs(north-south);
            int y=abs(east-west);

            int ini=x+y;

            int dis=ini+min((i+1)-ini, 2*k); // ensure we change dir such that change will be atmost k;

            ans=max(ans, dis);
        }

        return ans;
    }
};



// Term	Meaning
// ini	                Current Manhattan distance from origin
// i + 1	            Total moves taken so far
// (i + 1) - ini	    The distance you "lost" due to opposite or cancelling moves
// 2 * k	            Maximum gain possible from k changes (each worth +2)