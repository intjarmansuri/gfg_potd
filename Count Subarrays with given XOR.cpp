/* --------------------------- Approach : HashMap --------------------------- */
// Time Complexity : O(N)
// Space Complexity : O(N)

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        unordered_map<long long, int>prefixXorCount;
        long long prefixXor = 0;
        int count = 0;
        
        for(int num : arr) {
            prefixXor ^= num;
            
            if(prefixXor == k) {
                count++;
            }
            
            long long requiredXor = prefixXor ^ k;
            if(prefixXorCount.find(requiredXor) != prefixXorCount.end()) {
                count += prefixXorCount[requiredXor];
            }
            
            prefixXorCount[prefixXor]++;
        }
        return count;
        
    }
};