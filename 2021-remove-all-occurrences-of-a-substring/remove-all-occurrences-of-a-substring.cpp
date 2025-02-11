class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n=s.size();

        while(s.find(part)!=string::npos){
            s.erase(s.find(part), part.size());
        }

        return s;
    }
};