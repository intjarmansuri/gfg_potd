/* -------------------- Approach : Sliding Window (Two Pointer) ---------------- */
// Time Complexity : O(N)
// Space Complexity : O(1)

class Solution {
  public:
    int maxOnes(vector<int>& arr, int m) {
        int n = arr.size();
        
        int i = 0;  // Start of the window
        int maxLen = 0;
        int zeroCount = 0;
        
        for(int j = 0; j < n; j++) {  // End of the window
            if(arr[j] == 0) {
                zeroCount++;
            }
            
            // Shrink the window from the left if zeroCount exceeds m
            while(zeroCount > m) {
                if(arr[i] == 0) {
                    zeroCount--;
                }
                i++;
            }
            maxLen = max(maxLen, j - i + 1);
        }
        return maxLen;
    }
};