class Solution {
  public:
    long long MOD = 1e9+7;
    long long powerMod(long long base, long long exp) {
        long long result = 1;
        
        while(exp > 0) {
            if(exp % 2 == 1) {
                result = (result * base) % MOD;
            }
            base = (base * base)% MOD;
            exp /= 2;
        }
        return result;
    }
    int distributeBalls(int n) {
        if(n < 2) return 0;
        
        long long totalWays = powerMod(2, n);
        long long result = (totalWays - 2 + MOD) % MOD;
        
        return result;
    }
};