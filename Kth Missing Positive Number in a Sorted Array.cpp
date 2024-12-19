/* -------------------------- Approach : Binary Search ----------------------------- */
// Time Complexity : O(log n)
// Space Complexity : O(1)

class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        int low = 0;
        int high = arr.size() - 1;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            int missingCount = arr[mid] - (mid + 1);
            
            if(missingCount < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low + k;
    }
};