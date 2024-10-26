/* ---------------- Approach : Using HashMap ---------------*/
// Time Complexity : O(N)
// Space Complexity : O(N)

class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        
        unordered_map<int, int> freqMap;
        vector<int> result;
        
        for(int num : arr) {
            freqMap[num]++;
        }
        
        for(auto& it : freqMap) {
            
            if(it.second > 1) {
                result.push_back(it.first);
            }
        }
        
        sort(begin(result), end(result));
        
        return result;
    }
};