class Solution {
  public:
    int rotateDelete(vector<int> &arr) {
        int sz = arr.size();
        int k = 1;
        
        while(sz > 1) {
            arr.insert(arr.begin(), arr.back());
            arr.pop_back();
            
            if (k > sz) {
                k = sz;
            }
            
            arr.erase(arr.end() - k);
            sz = arr.size();
            k++;
        }
        return arr[0];
    }
};