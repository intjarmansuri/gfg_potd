class Solution {
  public:
    vector<int> rearrange(vector<int>& arr) {
        int n = arr.size();
        
        for(int i = 0; i < n; i++) {
            
            while(arr[i] != -1 && arr[i] != i) {
                swap(arr[i], arr[arr[i]]);
            }
        }
        return arr;
    }
};