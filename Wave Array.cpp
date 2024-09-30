class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to sort the array into a wave-like array.
    void convertToWave(int n, vector<int>& arr){
        
        // Traverse the array in steps of 2
    for (int i = 1; i < n; i += 2) {

            swap(arr[i], arr[i - 1]);
        }
    }
};