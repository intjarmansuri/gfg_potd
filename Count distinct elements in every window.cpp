/* ------------------------------ Approach : Naive Approach ------------------------------ */
// Time Complexity : O(Nk)
// Space Complexity : O(k)

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        int n = arr.size();
        
        vector<int> result;
        
        for(int i = 0; i <= n-k; i++) {
            unordered_set<int> st;
            
            for(int j = i; j < i+k; j++) {
                st.insert(arr[j]);
            }
            result.push_back(st.size());
        }
        return result;
    }
};


/* ------------------------------ Approach : Hashing ------------------------------ */
// Time Complexity : O(N)
// Space Complexity : O(k)

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        int n = arr.size();
        
        vector<int> result;
        unordered_map<int, int> freq;
        
        for(int i = 0; i < k; i++) {
            freq[arr[i]]++;
        };
        
        result.push_back(freq.size());
        
        // Traverse remaining loop
        for(int i = k; i < n; i++) {
            freq[arr[i - k]]--;
            
            if(freq[arr[i-k]] == 0) {
                freq.erase(arr[i-k]);
            }
            
            freq[arr[i]]++;
            
            result.push_back(freq.size());
        }
        return result;
    }
};