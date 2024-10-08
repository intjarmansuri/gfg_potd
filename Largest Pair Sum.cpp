class Solution {
  public:
    int pairsum(vector<int> &arr) {
        
        int firstMax = 0, secondMax = 0;
        
        for(int num : arr) {
            
            if(num > firstMax) {
                secondMax = firstMax;
                firstMax = num;
            }
            else if(num > secondMax) {
                secondMax = num;
            }
        }
        
        return firstMax + secondMax;
    }
};