/* ---------------- Approach : Using maxSum (Kadane Algorithm), and minSum (Kadane algorithm) ----------------- */
// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        int maxSum = arr[0];
        int currSum = arr[0];
        
        for(int i = 1; i < arr.size(); i++) {
            
            currSum = max(arr[i], currSum + arr[i]);
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
    
    int minSubarraySum(vector<int> &arr) {
        int minSum = arr[0];
        int currSum = arr[0];
        
        for(int i = 1; i < arr.size(); i++) {
            currSum = min(arr[i], currSum + arr[i]);
            minSum = min(minSum, currSum);
        }
        return minSum;
    }
    
    int circularSubarraySum(vector<int> &arr) {

        int maxSum = maxSubarraySum(arr);
        int totalSum = 0;
        
        for(int num : arr) {
            totalSum += num;
        }
        
        int minSum = minSubarraySum(arr);
        
        if(totalSum == minSum) {
            return maxSum;
        }
        
        return max(maxSum, totalSum - minSum);
    }
};