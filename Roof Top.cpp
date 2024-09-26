class Solution {
  public:
    int maxStep(vector<int>& arr) {
        int n = arr.size();
        int maxSteps = 0;
        int currSteps = 0;
        
        for(int i = 1; i < n; i++) {
            if(arr[i] > arr[i-1]) {
                currSteps++;
            } else {
                maxSteps = max(maxSteps, currSteps);
                currSteps = 0;
            }
        }
        
        return max(maxSteps, currSteps);
    }
};