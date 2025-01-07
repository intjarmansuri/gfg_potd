/* ----------------------------- Approach : Two Pointer Technique --------------------------- */
// Time Complexity : O(N)
// Space Complexity : O(1)

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int n = arr.size();
        int i = 0, j = n-1;
        int count = 0;
        
        while(i < j) {
            int sum = arr[i] + arr[j];
            
            if(sum == target) {
                
                if(arr[i] == arr[j]) {
                    int k = j - i + 1;
                    count += (k * (k - 1)) /2;
                    break;
                } else {
                    int leftVal = arr[i];
                    int rightVal = arr[j];
                    int leftCount = 0, rightCount = 0;
                    
                    // Count duplicates for arr[i]..... 
                    while(i < j && arr[i] == leftVal) {
                        i++;
                        leftCount++;
                    }
                    
                    // Count duplicates for arr[j]
                    while(j >= i && arr[j] == rightVal) {
                        j--;
                        rightCount++;
                    }
                    count += leftCount * rightCount;
                    
                }
                 
            } else if(sum < target) {
                i++;
            } else {
                j--;
            }
        }
        return count;
    }
};