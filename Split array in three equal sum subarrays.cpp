/* ------------------ Approach : Brutforce ----------------- */
// Time Complexity : O(N^3)
// Space Complexity : O(1)

class Solution {
  public:
    // Function to determine if array arr can be split into three equal sum sets.
    vector<int> findSplit(vector<int>& arr) {
        int n = arr.size();
        
        for(int i = 0; i < n-2; i++) {
            
            for(int j = i+1; j < n-1; j++) {
                
                int sum1 = accumulate(arr.begin(), arr.begin()+i+1, 0);
                
                int sum2 = accumulate(arr.begin()+i+1, arr.begin()+j+1, 0);
                
                int sum3 = accumulate(arr.begin()+j+1, arr.end(), 0);
                
                if(sum1 == sum2 && sum2 == sum3) {
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }
};


/* ------------------ Optimal Approach : Calculate Total Sum ----------------- */
// Time Complexity : O(N)
// Space Complexity : O(1)

class Solution {
  public:
    // Function to determine if array arr can be split into three equal sum sets.
    vector<int> findSplit(vector<int>& arr) {
        int n = arr.size();
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        
        if(totalSum % 3 != 0) {
            return {-1, -1};
        }
        
        int target = totalSum/3;
        int currSum = 0;
        
        int firstCut = -1, secondCut = -1;
        
        for(int i = 0; i < n; i++) {
            currSum += arr[i];
            
            if(currSum == target && firstCut == -1) {
                firstCut = i;
            }
            else if(currSum == 2 * target && firstCut != -1) {
                secondCut = i;
                break;
            }
        }
        
        if(secondCut != -1) {
            return {firstCut, secondCut};
        }
        
        return {-1, -1};
    }
};