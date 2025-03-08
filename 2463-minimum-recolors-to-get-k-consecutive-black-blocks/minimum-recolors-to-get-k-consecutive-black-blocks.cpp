class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.size();

        int l=0,r=0;

        int w=0,ops=k;

        while(r<n){
            if(blocks[r]=='W'){
                w++;
            }

            if(r-l+1==k){
                ops=min(ops,w);

                if(blocks[l]=='W'){
                    w--;
                }
                l++;
            }
            r++;
        }

        return ops;
    }
};