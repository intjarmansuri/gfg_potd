class Solution {
  public:
    // Returns count buildings that can see sunlight
    int countBuildings(vector<int> &height) {
        int n = height.size();
        
        int count = 1;
        int max_height = height[0];
        
        for(int i = 1; i < n; i++) {
            if(height[i] > max_height) {
                count++;
                max_height = height[i];
            }
        }
        return count;
    }
};