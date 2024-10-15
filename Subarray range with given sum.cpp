/* --------------- Approach - Using PrefixSum, HashMap 
Time Complexity : O(N)
Space Complexity : O(N) ----------------- */

class Solution {
  public:
    // Function to count the number of subarrays which adds to the given sum.
    int subArraySum(vector<int>& arr, int tar) {
        
        unordered_map<int, int> prefixSum;
        int currSum = 0;
        int count = 0;
        
        prefixSum[0] = 1;
        
        for(int i = 0; i < arr.size(); i++) {
            currSum += arr[i];
            
            if(prefixSum.find(currSum - tar) != prefixSum.end()) {
                count += prefixSum[currSum - tar];
            }
            prefixSum[currSum]++;
        }
        return count;
    }
};