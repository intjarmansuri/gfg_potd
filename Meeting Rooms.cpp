/* --------------------- Approach : Sorting and Check Overlaps ------------------- */
// Time Complexity : O(n log n)
// Space Complexity : O(1)

class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        
        sort(begin(arr), end(arr));
        
        for(int i = 1; i < arr.size(); i++) {
            
            if(arr[i][0] < arr[i-1][1]) {
                
                return false;
            }
        }
        return true;
    }
};