/* ------------------------------ Approach : Two Pointer Technique ------------------------------ */
// Time Complexity : O(n log n)
// Space Complexity : O(1)

class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        int n = arr.size();
        
        if(n < 2) return {};
        
        sort(begin(arr), end(arr));
        int i = 0, j = n-1;
        int diff = INT_MAX;
        
        vector<int> result;
        
        while(i < j) {
            int sum = arr[i] + arr[j];
            
            if(abs(target - sum) < diff) {
                diff = min(abs(target - sum), diff);
                result = {arr[i], arr[j]};
            }
            
            if(sum < target) {
                i++;
            } else {
                j--;
            }
        }
        return result;
    }
};