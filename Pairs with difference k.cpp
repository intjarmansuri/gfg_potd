/* ------------------- Approach : HashMap ---------------- */
// Time Complexity : O(N)
// Space Complexity : O(N)

class Solution {
  public:
    int countPairsWithDiffK(vector<int>& arr, int k) {
        
        unordered_map<int, int> freq;
        int pairCount = 0;

        for (int x : arr) {
            // Agar (x + k) map mein hai, toh pair mil gaya
            if (freq.count(x + k)) {
                pairCount += freq[x + k];
            }
            // Agar (x - k) map mein hai, toh pair mil gaya
            if (freq.count(x - k)) {
                pairCount += freq[x - k];
            }
            // Current element ko map mein count increment karte hain
            freq[x]++;
        }
        
        return pairCount;
    }
};