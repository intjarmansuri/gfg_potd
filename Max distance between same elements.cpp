class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        int n = arr.size();
        
        unordered_map<int, int> mp;
        int maxDist = 0;
        
        for(int i = 0; i < n; i++) {
            
            if(mp.find(arr[i]) == mp.end()) {
                mp[arr[i]] = i;
            }
            else {
                int dist = i - mp[arr[i]];
                maxDist = max(maxDist, dist);
            }
        }
        return maxDist;
    }
};