/* ------------------------ Approach : Binary Search -----------------------------*/
// Time Complexity : O(log n)
// Space Complexity : O(1)

class Solution {
  public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        
        int s = 0;
        int e = n-1;
        
        if(arr[s] <= arr[e]) {
            return arr[s];
        }
        
        while(s <= e) {
            int mid = s + (e - s)/2;
            
            if(mid > 0 && arr[mid] > arr[mid+1]) {
                return arr[mid+1];
            }
            
            if (mid < n - 1 && arr[mid] > arr[mid + 1]) {
                return arr[mid + 1];
            }
            
            if(arr[mid] >= arr[s]) {
                s = mid+1;
            } else {
                e = mid-1;
            }
        }
        return -1;
    }
};