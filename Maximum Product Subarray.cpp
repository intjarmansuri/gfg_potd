/* ------------------ Approach-1 : Brutforce (Naive Approach) ---------------- */
// Time Complexity : O(n^2)
// Spce Complexity : O(1)

class Solution {
  public:

    int maxProduct(vector<int> &arr) {
        int n = arr.size();
        
        int result = arr[0];
        
        for(int i = 0; i < n; i++) {
            
            int mul = 1;
            
            for(int j = i; j < n; j++) {
                
                mul *= arr[j];
                
                result = max(result, mul);
            }
        }
        return result;
    }
};

/* ------------------ Approach-2 : Using minimum and maximum product ---------------- */
// Time Complexity : O(n)
// Spce Complexity : O(1)

class Solution {
  public:
    
    int maxProduct(vector<int> &arr) {
        int n = arr.size();
        
        int maxProd = arr[0];
        int minProd = arr[0];
        int result = arr[0];
        
        for(int i = 1; i < n; i++) {
            
            if(arr[i] < 0) {
                swap(maxProd, minProd);
            }
            
            maxProd = max(arr[i], arr[i] * maxProd);
            minProd = min(arr[i], arr[i] * minProd);
            
            result = max(result, maxProd);
        }
        return result;
    }
};