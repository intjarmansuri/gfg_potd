/* ------------------- Brute-force Approach ------------------ */
// Time Complexity: O(n^3)
// Space Complexity : O(1)

class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        
        vector<vector<int>> result;
        int n = arr.size();

        // Teen nested loops
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    // Triplet ka sum check karo
                    if (arr[i] + arr[j] + arr[k] == 0) {
                        result.push_back({i, j, k});
                    }
                }
            }
        }

        return result;
    }
};