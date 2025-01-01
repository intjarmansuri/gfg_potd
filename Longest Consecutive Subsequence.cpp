/* ------------------- Approach : Hashset  -----------------------*/
// Time Complexity : O(N)
// Space Complexity : O(N)

class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        
        unordered_set<int> nums(arr.begin(), arr.end());
        int maxLength = 0;

        for (int num : nums) {
            // Check if this is the start of a sequence
            if (nums.find(num - 1) == nums.end()) {
                int currentNum = num;
                int currentLength = 1;
    
                // Count the length of the sequence
                while (nums.find(currentNum + 1) != nums.end()) {
                    currentNum++;
                    currentLength++;
                }
    
                // Update maximum length
                maxLength = max(maxLength, currentLength);
            }
        }
        return maxLength;
    }
};