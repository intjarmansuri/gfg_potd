class Solution {
  public:
    void sort012(vector<int>& arr) {
        int n = arr.size();
        
        int zeros = 0;
        int ones = 0;
        
        for(int i = 0; i < n; i++) {
            if(arr[i] == 0) zeros++;
            else if(arr[i] == 1)ones++;
        }
        
        for(int i = 0; i < n; i++) {
            if(zeros) {
                arr[i] = 0;
                zeros--;
            }
            else if(ones) {
                arr[i] = 1;
                ones--;
            }
            else {
                arr[i] = 2;
            }
        }
    }
};