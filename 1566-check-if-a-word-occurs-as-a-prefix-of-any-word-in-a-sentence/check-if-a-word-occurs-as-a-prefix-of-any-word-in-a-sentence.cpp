class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream stream(sentence);
        string word;
        int index = 0;
        
        while (stream >> word) {
            index++; // Increment index for each word
            
            if (word.find(searchWord) == 0) { // Check if searchWord is a prefix
                return index; // Return the 1-based index
            }
        }
        
        return -1;
    }
};