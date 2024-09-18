/*----------- Approach 1: Using Stack -----------*/

class Solution {
  public:
    int maxLength(string& str) {
        int n = str.length();
        stack<int> st;
        st.push(-1);  // initial base for calculating lengths
        int maxLen = 0;
        
        for(int i = 0; i < n; i++) {
            if(str[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                
                if(st.empty()) {
                    st.push(i);
                } else {
                    maxLen = max(maxLen, i - st.top());
                }
            }
        }
        return maxLen;
    }
};

/*----------- Approach 2: Two Pointer -----------*/

class Solution {
  public:
    int maxLength(string& str) {
        int n = str.length();
        int left = 0, right = 0;
        int maxLen = 0;
        
        // Left to right pass
        for (int i = 0; i < n; i++) {
            if (str[i] == '(') {
                left++;
            } else {
                right++;
            }
            
            if (left == right) {
                maxLen = max(maxLen, 2 * right);  // Valid substring
            } else if (right > left) {
                left = right = 0;
            }
        }
        
        // Right to left pass
        left = right = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (str[i] == '(') {
                left++;
            } else {
                right++;
            }
            
            if (left == right) {
                maxLen = max(maxLen, 2 * left);  // Valid substring
            } else if (left > right) {
                left = right = 0; 
            }
        }
        
        return maxLen;
    }
};