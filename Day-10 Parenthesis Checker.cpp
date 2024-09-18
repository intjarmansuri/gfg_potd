class Solution {
public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x) {
        stack<char> st;
        
        for(char ch : x) {
            if(ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }
            else {
                if(st.empty()) return false;
                
                char top = st.top();
                st.pop();
                
                if((ch == ')' && top != '(') ||
                   (ch == '}' && top != '{') ||
                   (ch == ']' && top != '[')) {
                    return false;
                }
            }
        }
        return st.empty();
    }
};