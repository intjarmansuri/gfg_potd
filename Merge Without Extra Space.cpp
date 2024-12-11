/* -------------------------- Approach : Two Pointer -----------------------*/
// Time Complexity : O(n log m)
// Space Complexity : O(1)

class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        
        int i = n-1;
        int j = 0;
        
        while(i >= 0 && j < m) {
            if(a[i] < b[j]) {
                break;
            }
            else {
                swap(a[i--], b[j++]);
            }
        }
        
        sort(begin(a), end(a));
        sort(begin(b), end(b));
        
        return;
    }
};