/* ------------------- Approach : String ----------------------*/
// Time Complexity : O(N)
// Space Complexity : O(1)

class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        int n = s.size();
        vector<bool> visited(26, false);
        int ans = 0;
        int i = 0, j = 0;
        
        while(j < n) {
            
            while(visited[s[j] - 'a'] == true) {
                visited[s[i] - 'a'] = false;
                i++;
            }
            
            visited[s[j] - 'a'] = true;
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};