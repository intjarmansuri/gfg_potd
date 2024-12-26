/* ------------------- Approach - 1 : Brutforce (Naive Approach) ------------------------ */
// Time Complexity : O(N^2)
// Space Complexity : O(1)

class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        int n = arr.size();
        
        for(int i = 0; i < n; i++) {
            
            for(int j = i+1; j < n; j++) {
                
                if(arr[i] + arr[j] == target) {
                    return true;
                }
            }
        }
        return false;
    }
};

/* ------------------- Approach - 2 : Two pointer Technique ------------------------ */
// Time Complexity : O(n log n)
// Space Complexity : O(1)

class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        sort(begin(arr), end(arr));
        
        int left = 0;
        int right = arr.size() - 1;
        
        while(left < right) {
            int sum = arr[left] + arr[right];
            if(sum == target) {
                return true;
            } 
            else if(sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return false;
    }
};

/* ------------------- Approach - 3 : Hashing (HashSet) ------------------------ */
// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        
        unordered_set<int> seen;
        
        for(int num : arr) {
            int complement = target - num;
            
            if(seen.find(complement) != seen.end()) {
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};
