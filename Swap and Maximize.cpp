/*-------------- Approach : Using Greedy --------------- */
// Time Complexity : O(nlogn)
// Space Complexity : O(1)

class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        int  n = arr.size(); 
        
        sort(begin(arr), end(arr));
        
        int sum = 0;
       
        for(int i = 0; i < n/2; i++) {
           
           sum -= (2* arr[i]);
           sum += (2 * arr[n - i - 1]);
        }
       
        return sum;
    }
};
