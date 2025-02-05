/* -------------------------- Approaach : Brutforce -------------------------*/
// Time Complexity : O(N^2)
// Space Complexity : O(1)

class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        int n = arr.size();
        
        for(int i = 0; i < n; i++) {
            int count = 0;
            
            for(int j = 0; j < n; j++) {
                
                if(arr[j] == arr[i]){
                    count++;
                }
            }
            
            if(count > n/2) return arr[i];
        }
        return -1;
    }
};

/* -------------------------- Approaach : Hashing -------------------------*/
// Time Complexity : O(N)
// Space Complexity : O(N)

class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        int n = arr.size();
        
        unordered_map<int, int>freq;
        
        for(int num : arr) {
            freq[num]++;
            
            if(freq[num] > n/2) return num;
        }
        return -1;
    }
};

/* -------------------------- Approaach : Sorting -------------------------*/
// Time Complexity : O(N Log N)
// Space Complexity : O(1)

