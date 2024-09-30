class Solution {
  public:
    pair<long long, long long> getMinMax(vector<long long int> arr) {
        int n = arr.size();
        
        long long mini = arr[0];
        long long maxi = arr[0];
        
        for(int i = 1; i < n; i++) {
            
            if(arr[i] < mini) {
                mini = arr[i];
            }
            
            if(arr[i] > maxi) {
                maxi = arr[i];
            }
            
        }
        return {mini, maxi};
    }
};