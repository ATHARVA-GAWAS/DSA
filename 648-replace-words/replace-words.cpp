class Solution {
public:

    string findRoot(string& word, unordered_set<string>& st) {

        //try all length substring starting from 0th index
        for(int l = 1; l <= word.length(); l++) {
            string root = word.substr(0, l);
            if(st.count(root)) {
                return root;
            }
        }

        return word;

    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> st(dictionary.begin(), dictionary.end());

        stringstream ss(sentence);
        string word;
        string ans;

        while(getline(ss, word, ' ')) {
            ans += findRoot(word, st) + " ";
        }

        ans.pop_back(); //to remove extra space at the end of the string
        return ans;

    }
};