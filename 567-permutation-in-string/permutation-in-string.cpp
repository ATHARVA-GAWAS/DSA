class Solution {
public:
    bool checkInclusion(string s1, string s2) {

       sort(s1.begin(),s1.end());
       
       int n=s1.size();

       int times=s2.size()-s1.size();

       for(int i=0;i<=times;i++){

           string sub=s2.substr(i,n);

           sort(sub.begin(),sub.end());

           if(sub==s1){
               return true;
           }   
       }
        return false;           
    }
};