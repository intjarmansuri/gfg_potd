/* ------------------------- Approach : Binary Search -------------------------- */
// Time Complexity : O(log(min(a, b)));
// Space Complexity : O(1)

class Solution {
  public:
    int binarySearch(vector<int>& vec, int k) {
        int n = vec.size();
        int s = 0, e = n-1;
        
        while(s <= e) {
            int mid = s + (e - s)/2;
            
            if (vec[mid] == k) {
                return mid;
            }

            if (vec[mid] < k) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return -1;
    }
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        int n = a.size();
        int m = b.size();
        
        vector<int> vec;
        int i = 0, j = 0;
        
        while(i < n && j < m) {
            if(a[i] < b[j]) {
                vec.push_back(a[i]);
                i++;
            }
            else {
                vec.push_back(b[j]);
                j++;
            }
        }
        
        while(i < n) {
            vec.push_back(a[i]);
            i++;
        }
        
        while(j < m) {
            vec.push_back(b[j]);
            j++;
        }
        
        if (k > 0 && k <= vec.size()) {
            return vec[k - 1];
        } else {
            return -1;
        }
        
        return binarySearch(vec, k);
    }
};