class Solution {
  public:
    int minRepeats(string& s1, string& s2) {
        
        string temp = s1;
        int count = 1;
        
        while (temp.length() < s2.length()) {
            temp += s1;
            count++;
        }
        
        if (temp.find(s2) != string::npos) {
            return count;
        }
        
        temp += s1;
        count++;
        if (temp.find(s2) != string::npos) {
            return count;
        }
    
        return -1;
    }
};