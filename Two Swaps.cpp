class Solution {
  public:
    bool checkSorted(vector<int> &arr) {
        
        int n = arr.size();
        int count = 0;
        
        for(int i = 0; i < n;) {
            
            if(arr[i] != i+1) {
                swap(arr[i], arr[arr[i]-1]);
                count++;
            }
            else i++;
        }
        if(count == 0 || count == 2) return true;
        return false;
    }
};