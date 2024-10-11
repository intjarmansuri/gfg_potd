class Solution {
  public:
    bool isAnagram(string str1, string str2) {
        
        if(str1.length() != str2.length()) {
            return false;
        }
        
        unordered_map<char, int> freq;
        
        for(char &ch : str1) {
            freq[ch]++;
        }
        
        for(char &ch : str2) {
            freq[ch]--;
            
            if(freq[ch] < 0) {
                return false;
            }
        }
        return true;
    }
};