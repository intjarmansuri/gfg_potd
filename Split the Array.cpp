class Solution {
  public:
    int countgroup(vector<int>& arr) {
        int n = arr.size();
        
        int totalXOR = 0;

        // Calculate the XOR of all elements in the array
        for(int i = 0; i < n; i++) {
            totalXOR ^= arr[i];
        }
        
        // If totalXOR is not zero, it's impossible to split the array into two equal XOR groups
        if(totalXOR != 0) {
            return 0;  // Return 0 as no valid split is possible
        }
        
        // Modulo value to handle large results
        int MOD = 1e9+7;
        int result = 1;
        
        // We calculate 2^(n-1) mod MOD
        // Since there are (n-1) possible places to split the array
        for(int i = 0; i < n-1; i++) {
            result = (result * 2) % MOD;  // Multiply result by 2 and take modulo MOD
        }
        return result - 1;
    }
};
