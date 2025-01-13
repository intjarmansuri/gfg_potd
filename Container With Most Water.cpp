/* -------------------------- Approach : Two Pointer Technique --------------------------- */
// Time Complexity : O(N)
// Space Complexity : O(1)

class Solution {

  public:
    int maxWater(vector<int> &arr) {
        int n = arr.size();
        
        int left = 0, right = n-1;
        int maxArea = 0;
        
        while(left < right) {
            int height = min(arr[left], arr[right]);
            int width = right - left;
            int currentArea = height * width;
            
            maxArea = max(maxArea, currentArea);
            
            if(arr[left] < arr[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxArea;
    }
};