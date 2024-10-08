class Solution {
  public:
    vector<int> findMajority(vector<int>& nums) {
        int n = nums.size();
        int candidate1 = nums[0], candidate2 = nums[0];
        int count1 = 0, count2 = 0;
        
        for(int num : nums) {
            if(num == candidate1) {
                count1++;
            }
            else if(num == candidate2) {
                count2++;
            }
            else if(count1 == 0) {
                candidate1 = num;
                count1 = 1;
            }
            else if(count2 == 0) {
                candidate2 = num;
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }
        
        count1 = count2 = 0;
        for(int num : nums) {
            if(num == candidate1) count1++;
            else if(num == candidate2) count2++;
        }
        
        vector<int> result;
        
        if(count1 > n/3) result.push_back(candidate1);
        if(count2 > n/3) result.push_back(candidate2);
        
        if (result.empty()) return {-1};

        return result;
    }
};