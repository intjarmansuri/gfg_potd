/* ------------------- Approach : Two Pointer -------------------- */
// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        int n = arr.size();
        int j = 0; // Pointer for non-zero elements
        
        // Move non-zero elements to the beginning
        for (int i = 0; i < n; i++) {
            if (arr[i] != 0) {
                arr[j] = arr[i];
                j++;
            }
        }
        
        // Fill the rest with zeroes
        while (j < n) {
            arr[j] = 0;
            j++;
        }
    }
};