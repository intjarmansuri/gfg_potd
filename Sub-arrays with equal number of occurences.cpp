/* ---------------- Approach : Hashmap 
Time Complexity : O(N)
Space Complexity : O(N) ------------- */

class Solution {
  public:
    int sameOccurrence(vector<int>& arr, int x, int y) {
        int n = arr.size();
        
        unordered_map<int, int> mp;
        mp[0] = 1;
        int countDiff = 0;
        int result = 0;
        
        for(int i = 0; i < n; i++) {
            if(arr[i] == x) {
                countDiff++;
            }
            else if(arr[i] == y) {
                countDiff--;
            }
            
            if(mp.find(countDiff) != mp.end()) {
                result += mp[countDiff];
            }
            
            mp[countDiff]++;
        }
        return result;
    }
};