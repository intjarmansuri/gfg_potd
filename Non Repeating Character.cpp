/* ------------------------- Naive Approach : Using two nested loops ---------------------- */
// Time Complexity : O(n^2)
// Space Complexity : O(1)

class Solution {
  public:
    
    char nonRepeatingChar(string &s) {
        int n = s.length();
        
        for(int i = 0; i < n; i++) {
            bool found = false;
            
            for(int j = 0; j < n; j++) {
                
                if(i != j && s[i] == s[j]) {
                    found = true;
                    break;
                }
            }
            
            if(found == false) {
                return s[i];
            }
        }
        return '$';
    }
};

/* ------------------------- Approach : Using Hashmap ---------------------- */
// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
  public:
    
    char nonRepeatingChar(string &s) {
        
        unordered_map<char, int> freq;
        
        for(char ch : s) {
            freq[ch]++;
        }
        
        for(char ch : s) {
            if(freq[ch] == 1) {
                return ch;
            }
        }
        return '$';
    }
};