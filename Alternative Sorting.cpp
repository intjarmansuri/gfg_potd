/* ---------------- Approach : Sorting and Two Pointer ---------------- */
// Time Complexity : O(nlogn)
// Space Complexity : O(n)

class Solution {
  public:
    vector<int> alternateSort(vector<int>& arr) {
        
        sort(begin(arr), end(arr));
        
        int i = 0;
        int j = arr.size()-1;
        
        vector<int> result;
        
        while(i < j) {  
            result.push_back(arr[j--]);
            result.push_back(arr[i++]);
        }
        if(i == j) {
            result.push_back(arr[i]);
        }
        return result;
    }
};