
/* ------------------- Approach : Using Cyclone Sorting ------------------ */
// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        int n = arr.size();
        
        for(int i = 0; i < n; i++) {
            while(arr[i] > 0 && arr[i] <= n && arr[i] != arr[arr[i] - 1]) {
                swap(arr[i], arr[arr[i] - 1]);
            }
        }
        
        for(int i = 0; i < n; i++) {
            if(arr[i] != i + 1) {
                return i+1;
            }
        }
        
        return n + 1;
    }
};