/* -------------------------- Approach : Sorting and String ------------------------ */
// Time Complexity : O(n log n)
// Space Complexity : O(n)

class Solution {
  public:
    string addStrings(string &num1, string &num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        
        string result;
        
        while(i >= 0 || j >= 0  || carry) {
            int sum = carry;
            
            if(i >= 0) {
                sum += num1[i] - '0';
                i--;
            }
            
            if(j >= 0) {
                sum += num2[j] - '0';
                j--;
            }
            
            result.push_back(sum % 10 + '0');
            carry = sum/10;
        }
        reverse(begin(result), end(result));
        
        // Remove leading zeroes by deleting the first character if it's '0'
        while (result[0] == '0' && result.size() > 1) {
            result.erase(result.begin());
        }

        return result;
    }
  
    string minSum(vector<int> &arr) {
        sort(begin(arr), end(arr));
        
        string num1, num2;
        
        for(int i = 0; i < arr.size(); i++) {
            
            if(i % 2 == 0) {
                num1 += to_string(arr[i]);
            } 
            else {
                num2 += to_string(arr[i]);    
            }
        }
        
        return addStrings(num1, num2);
    }
};