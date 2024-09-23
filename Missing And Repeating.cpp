/* ------ Approach : 1, T.C : O(N), S.C : O(N) -------- */

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        vector<int> ans(2);
        unordered_map<int, int> mp;
        
        for(int num : arr) {
            mp[num]++;
        }
        
        for (int i = 1; i <= arr.size(); i++) {
            if (mp[i] == 2) {
                ans[0] = i;  // Repeating number
            } else if (mp[i] == 0) {
                ans[1] = i;  // Missing number
            }
        }
        return ans;
    }
};

/* ------ Approach : 1, T.C : O(N), S.C : O(1) -------- */

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        long long n = arr.size();
        long long S = (long long)n * (n + 1) / 2;
        long long P = (long long)n * (n + 1) * (2 * n + 1) / 6;
        
        long long S_actual = 0, P_actual = 0;
        
        for (int i = 0; i < n; i++) {
            S_actual += arr[i];
            P_actual += (long long)arr[i] * arr[i];
        }
        
        long long diff_S = S - S_actual;
        long long diff_P = P - P_actual;
        
        long long sum_XY = diff_P / diff_S;
        
        long long X = (diff_S + sum_XY) / 2; // Missing number
        long long Y = sum_XY - X;            // Repeating number
        
        return {(int)Y, (int)X};
    }
};