class Solution {
public:
    char kthCharacter(int k) {
        string w="a";

        while(w.size()<k){
            string x=w;

            for(auto &it:x){
                if(it=='z'){
                    it='a';
                }
                else{
                    it=it+1;
                }
                
            }

            w=w+x;
        }
        return w[k-1];
    }
};