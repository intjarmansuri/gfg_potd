/* --------------------------- Approach : Binary Search -------------------------*/
// Time Complexity : O(n log n)
// Space Complexity : O(1)

class Solution {
  public:
    
    bool canPlaceCows(vector<int>& stalls, int k, int minDist) {
        int cowPlaced = 1;
        int lastPosition = stalls[0];
        
        for(int i = 1; i < stalls.size(); i++) {
            if(stalls[i] - lastPosition >= minDist) {
                cowPlaced++;
                lastPosition = stalls[i];
            }
            if(cowPlaced == k) {
                return true;
            }
        }
        return false;
    }

    int aggressiveCows(vector<int> &stalls, int k) {

        sort(begin(stalls), end(stalls));
        
        // Binary search for maximum minimum distance
        int low = 1;
        int high = stalls.back() - stalls.front();
        int result = 0;
        
        while(low <= high) {
            int mid = low + (high - low)/2;
            
            if(canPlaceCows(stalls, k, mid)) {
                result = mid;
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        return result;
    }
};