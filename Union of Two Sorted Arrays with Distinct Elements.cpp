/* ----------------------- Approach : Using Merge Step of Merge Sort ------------------- */
// Time Complexity : O(n + m)
// Space Complexity : O(1)

class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        int n = a.size(), m = b.size();
        
        int i = 0, j = 0;
        vector<int> result;
        
        while(i < n && j < m) {
            
            if(a[i] < b[j]) {
                result.push_back(a[i]);
                i++;
            }
            else if(a[i] > b[j]) {
                result.push_back(b[j]);
                j++;
            } else {
                result.push_back(a[i]);
                i++;
                j++;
            }
            
        }
        
        while(i < n) {
            result.push_back(a[i]);
            i++;
        }
        
        while(j < m) {
            result.push_back(b[j]);
            j++;
        }
        
        return result;
    }
};
