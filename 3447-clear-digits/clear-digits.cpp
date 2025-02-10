class Solution {
public:
    string clearDigits(string s) {
        string stack; // Acts as a stack
        
        for (char c : s) {
            if (isdigit(c)) { 
                if (!stack.empty()){
                    stack.pop_back(); // Remove closest non-digit character
                } 
            } else {
                stack.push_back(c); // Store non-digit characters
            }
        }
        return stack;
    }
};