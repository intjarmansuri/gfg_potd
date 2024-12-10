/* -------------------------- Approach : Greedy -----------------------------*/
// Time Complexity : O(n log n)
// Space Complexity : O(1)


class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
        
        sort(begin(intervals), end(intervals), [](vector<int>&a,
        vector<int>&b) {
            return a[1] < b[1];
        });
        
        int prevEnd = INT_MIN;
        int removals = 0;
        
        for(auto & interval : intervals) {
            if(interval[0] < prevEnd) {
                removals++;
            } else {
                prevEnd = interval[1];
            }
        }
        return removals;
    }
};