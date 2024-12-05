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


/* ------------------------ Approach : Dutch National Flag Algorithm ------------------------*/
// Time Complexity : O(n)
// Space Compelxity : O(1)


class Solution {
  public:
    void sort012(vector<int>& arr) {
        int low = 0;
        int mid = 0;
        int high = arr.size() - 1;
        
        while(mid <= high) {
            if(arr[mid] == 0) {
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            } else if(arr[mid] == 1) {
                mid++;
            } else {
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }
};