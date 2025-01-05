/* ------------------------------ Approach : Brutforce ------------------------------*/
// Time Complexity : O(N^2)
// Space Complexity : O(1)

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int n = arr.size();
        int count = 0;
        
        for(int i = 0; i < n; i++) {
            
            for(int j = i+1; j < n; j++) {
                
                if(arr[i] + arr[j]  < target) {
                    count++;
                }
            }
        }
        return count;
    }
};


/* ------------------------------ Approach : Two Pointer Technique ------------------------------*/
// Time Complexity : O(N log N)
// Space Complexity : O(1)

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int n = arr.size();

        sort(begin(arr), end(arr));
        int left = 0;
        int right = n-1;
        int count = 0;
        
        while(left < right) {
            int sum = arr[left] + arr[right];
            if(sum < target) {
                count += (right - left);
                left++;
            } else {
                right--;
            }
        }
        return count;
    }
};