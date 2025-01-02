/* -------------------- Approach : Brutfroce --------------------*/
// Time Complexity : O(N^2)
// Space Complexity : O(1)

class Solution {
  public:
    int countSubarrays(vector<int> &arr, int k) {
        int n = arr.size();
        int count = 0;
        
        for(int i = 0; i < n; i++) {
            int totalSum = 0;
            
            for(int j = i; j < n; j++) {
                totalSum += arr[j];
                if(totalSum == k) {
                    count++;
                }
            }
        }
        return count;
    }
};

/* -------------------- Approach : HashMap (Prefix Sum) --------------------*/
// Time Complexity : O(N)
// Space Complexity : O(N)

class Solution {
  public:
    int countSubarrays(vector<int> &arr, int k) {
       unordered_map<int, int> prefixSumCount;
       int currSum = 0;
       int count = 0;
       
       prefixSumCount[0] = 1;
       
       for(int num : arr) {
           currSum += num;
           
           if(prefixSumCount.find(currSum - k) != prefixSumCount.end()) {
               count += prefixSumCount[currSum - k];
           }
           
           prefixSumCount[currSum]++;
       }
       return count;
       
    }
};