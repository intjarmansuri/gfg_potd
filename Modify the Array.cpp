/* ------------ Approach - 1 : Brute Force with Extra Space
Time Complexity : O(N)
Space Complexity : O(N) ---------------- */

class Solution {
  public:
    vector<int> modifyAndRearrangeArray(vector<int> &arr) {
        int n = arr.size();
        
        // Modify array as per the given condition
        for(int i = 0; i < n-1; i++) {
            if(arr[i] == arr[i+1] && arr[i] != 0) {
                arr[i] = arr[i]*2;
                arr[i+1] = 0;
            }
        }
        
        // Rearrange array by moving non-zero elements to the front
        vector<int> result;
        for(int i = 0; i < n; i++) {
            if(arr[i] != 0) {
                result.push_back(arr[i]);
            }
        }
        
        // Append remaining zeroes at the end
        while(result.size() < n) {
            result.push_back(0);
        }
        
        return result;
    }
};

/* ------------ Approach - 2 : Two-Pointer Technique(Optimize)
Time Complexity : O(N)
Space Complexity : O(1) ---------------- */

class Solution {
  public:
    vector<int> modifyAndRearrangeArray(vector<int> &arr) {
        int n = arr.size();
        
        // Modify array as per the given condition
        for(int i = 0; i < n-1; i++) {
            if(arr[i] == arr[i+1] && arr[i] != 0) {
                arr[i] = arr[i]*2;
                arr[i+1] = 0;
            }
        }
        
        // Shift all non-zero elements to the front and zeroes to the end
        int index = 0;
        
         // Move all non-zero elements to the front
        for(int i = 0; i < n; i++) {
            if(arr[i] != 0) {
                arr[index++] = arr[i];
            }
        }
         
        // Fill the remaining positions with 0s
        while(index < n) {
            arr[index++] = 0; 
        }
        
        return arr;
    }
};