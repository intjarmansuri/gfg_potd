// Time Complexity : O(N^2)
// Space Complexity : O(1)

class Solution{
public:	
	
	void rotateMatrix(vector<vector<int>>& arr, int n) {
	    // Step 1: Transpose the matrix
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(arr[i][j], arr[j][i]);
            }
        }
    
        // Step 2: Reverse each column
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n / 2; i++) {
                swap(arr[i][j], arr[n - i - 1][j]);
            }
        }
	}

};