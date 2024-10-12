/* --------------- Brutforce (TLE) ------------- */

class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        long maxSum = INT_MIN;
        
        for(int i = 0; i <= N-K; i++) {
            
            long sum = 0;
            
            for(int j = i; j < i+K; j++) {
                sum += Arr[j];
            }
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};

/* --------------- Sliding Window, O(N), O(1) ------------- */

class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        long currSum = 0;
        
        for(int i = 0; i < K; i++) {
            currSum += Arr[i];
        }
        
        long windowSum = currSum;
        
        for(int i = K; i < N; i++) {
            currSum += Arr[i] - Arr[i - K];
            windowSum = max(windowSum, currSum);
        }
        return windowSum;
    }
}