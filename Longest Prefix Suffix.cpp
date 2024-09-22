class Solution {
  public:
    int lps(string str) {
        int n = str.length();
        int pfx = 0;
        int sfx = 1;
        int pos = 1;
        int count = 0;
        
        while(pfx < n && sfx < n) {
            if(str[pfx] == str[sfx]) {
                pfx++;
                sfx++;
                count++;
            }
            else {
                pfx = 0;
                pos++;
                sfx = pos;
                count = 0;
            }
        }
        return count;
    }
};