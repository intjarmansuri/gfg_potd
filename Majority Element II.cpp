/* -------------------- Approach : Moore’s Voting Algorithm ka extended version ---------------------- */
// Time Complexity : O(N)
// Space Complexity : O(1)

class Solution {
  public:
  
    vector<int> findMajority(vector<int>& arr) {
        int n = arr.size();
        int candidate1 = arr[0];
        int candidate2 = arr[0];
        int count1 = 0;
        int count2 = 0;
        
        // Find potential candidates
        for(int i = 0; i < n; i++) {
            if(arr[i] == candidate1) {
                count1++;
            }
            else if(arr[i] == candidate2) {
                count2++;
            }
            else if(count1 == 0) {
                candidate1 = arr[i];
                count1 = 1;
            }
            else if(count2 == 0) {
                candidate2 = arr[i]; ;
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }
        
        // Validate the candidates
        count1 = count2 = 0;
        for(int i = 0; i < n; i++) {
            if(arr[i] == candidate1) {
                count1++;
            }
            else if(arr[i] == candidate2) {
                count2++;
            }
        }
        
        vector<int> result;
        
        if(count1 > n/3) result.push_back(candidate1);
        if(count2 > n/3) result.push_back(candidate2);
        
        sort(result.begin(), result.end());
        return result;
    }
};