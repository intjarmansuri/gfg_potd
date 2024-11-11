/* ------------------------ Approach : Use Sorting -------------------------*/
// Time Complexity : O(n log(n))
// Space Complexity : O(1)

class Solution {
  public:
    int minIncrements(vector<int>& arr) {
        
        sort(begin(arr), end(arr));
        int count = 0;
        
        for(int i = 1; i < arr.size(); i++) {
            
            if(arr[i] <= arr[i-1]) {
                
                count += arr[i-1] + 1 - arr[i];
                arr[i] = arr[i - 1] + 1;
            }
        }
        return count;
    }
};
