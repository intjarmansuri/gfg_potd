/* --------------- Approach : BrutForce --------------  */
// Time Complexity : O(N^2);
// Space Complexity : O(1)

class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int n = arr.size();
        
        for(int i = 0; i < n; i++) {
            int sum = 0;
            
            for(int j = i; j < n; j++) {
                
                sum += arr[j];
                if(sum == target) {
                    return {i+1, j+1};   // 1-based indices;
                }
            }
        }
        return {-1};
    }
};

/* --------------- Approach : Sliding Window --------------  */
// Time Complexity : O(N);
// Space Complexity : O(1)

class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int n = arr.size();
        
        for(int i = 0; i < n; i++) {
            int sum = 0;
            
            for(int j = i; j < n; j++) {
                
                sum += arr[j];
                if(sum == target) {
                    return {i+1, j+1};   // 1-based indices;
                }
            }
        }
        return {-1};
    }
};

/* --------------- Approach : PreFixSum --------------  */
// Time Complexity : O(N);
// Space Complexity : O(N)

class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int n = arr.size();
        
        unordered_map<int, int> mp;
        int prefixSum = 0;
        
        mp[0] = 0;
        
        for(int i = 0; i < n; i++) {
            prefixSum += arr[i];
            
            if(mp.find(prefixSum - target) != mp.end()) {
                
                return {mp[prefixSum - target]+1, i+1};
            }
            
            mp[prefixSum] = i + 1;
        }
        return {-1};
    }
};