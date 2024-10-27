/* ----------------- Approach : Sorting and Two Pointer -------------*/
// Time Comlexity : O(n^2)
// Space Comp,exity : O(1)

class Solution {
  public:
    bool findTriplet(vector<int>& arr) {
        int n = arr.size();
        
        sort(begin(arr), end(arr));
        
        for(int k = n-1; k >= 0; k--) {
            int target = arr[k];
            int i = 0, j = k-1;
            
            
            while(i < j) {
                
                int sum = arr[i] + arr[j];
                
                if(sum == target) {
                    return true;
                }
                else if(sum < target) {
                    i++;
                }
                else {
                    j--;
                }
            }   
        }
        return false;
    }
};