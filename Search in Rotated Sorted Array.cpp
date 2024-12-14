/* --------------------- Approach : Binary Search -------------------- */
// Time Complexity : O(log n)
// Space Complexity : O(1)

class Solution {
  public:
    int search(vector<int>& arr, int key) {
        int s = 0;
        int e = arr.size() - 1;
        
        while(s <= e) {
            int mid = s + (e - s)/2;
            
            if(arr[mid] == key) {
                return mid;
            }
            
            if (arr[s] <= arr[mid]) {
                // Left half is sorted
                if (key >= arr[s] && key < arr[mid]) {
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }
            } else {
                // Right half is sorted
                if (key > arr[mid] && key <= arr[e]) {
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            }
        }
        return -1;
    }
};