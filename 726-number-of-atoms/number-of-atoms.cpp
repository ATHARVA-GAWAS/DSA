class Solution {
public:
    string countOfAtoms(string formula) {
        int n=formula.size();
        stack<unordered_map<string,int>> st;
        st.push(unordered_map<string,int>());

        int i=0;

        while(i<n){
            if(formula[i]=='('){
                st.push(unordered_map<string,int>());
                i++;
            }
            else if(formula[i]==')'){
                unordered_map<string,int> currmap=st.top();
                st.pop();
                i++;
                string multiplier;

                while(i<n && isdigit(formula[i])){
                    multiplier+=formula[i];
                    i++;
                }
                if(!multiplier.empty()){
                    int mult=stoi(multiplier);

                    for(auto &[atom,count]:currmap){
                        currmap[atom]=count*mult;
                    }
                }

                for(auto &[atom,count]:currmap){
                    st.top()[atom]+=count;
                }
            }
            else{
                string curratom;
                curratom+=formula[i];
                i++;
                while(i<n && islower(formula[i])){
                    curratom+=formula[i];
                    i++;
                }
                string currCount;

                while(i<n && isdigit(formula[i])){
                    currCount+=formula[i];
                    i++;
                }
                int count=currCount.empty()?1:stoi(currCount);
                st.top()[curratom]+=count;
            }
        }

        map<string,int> sortedmap(begin(st.top()),end(st.top()));

        string res;
        for (auto& [atom, count] : sortedmap) {
            res += atom;
            if (count > 1) {
                res += to_string(count);
            }
        }

        return res;
    }
};