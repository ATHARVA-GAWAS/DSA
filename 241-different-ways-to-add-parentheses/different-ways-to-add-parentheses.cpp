class Solution {
    vector<int> f(string s){
        vector<int> res;

        for(int i=0;i<s.length();i++){
            if(s[i]=='+' || s[i]=='-' || s[i]=='*'){
                vector<int> l=f(s.substr(0,i));
                vector<int> r=f(s.substr(i+1));

                for(int &x:l){
                    for(int &y:r){
                        if(s[i]=='+'){
                            res.push_back(x+y);
                        }
                        else if(s[i]=='-'){
                            res.push_back(x-y);
                        }
                        else{
                            res.push_back(x*y);
                        }
                    }
                }
            }
        }
        if(res.empty()){
            res.push_back(stoi(s));
        }

        return res;
    }
public:
    vector<int> diffWaysToCompute(string expression) {
        return f(expression);
    }
};