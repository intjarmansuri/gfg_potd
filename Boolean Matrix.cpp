/* ------------------- Brutforce Approach ----------------------- */
// Time Complexity : O(R x C)
// Space Complexity : O(R + C)

class Solution
{   
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int> > &matrix)
    {
        int R = matrix.size();
        int C = matrix[0].size();
        
        vector<int> row(R, 0);
        vector<int> col(C, 0);
        
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                if(matrix[i][j] == 1) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                if(row[i] == 1 || col[j] == 1) {
                    matrix[i][j] = 1;
                }
            }
        }
    }
};

/* ------------------- Optimal Approach Using First Row and First Column as Markers  ----------------------- */
// Time Complexity : O(R x C)
// Space Complexity : O(1)

class Solution
{   
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int> > &matrix)
    {
        int R = matrix.size();
        int C = matrix[0].size();
        
        bool firstRowHasOne = false, firstColHasOne = false;
        
        // Check if the first row has any 1s
        for(int j = 0; j < C; j++) {
            if(matrix[0][j] == 1) {
                firstRowHasOne = true;
                break;
            }
        }
        
        // Check if the first column has any 1s
        for(int i = 0; i < R; i++) {
            if(matrix[i][0] == 1) {
                firstColHasOne = true;
                break;
            }
        }
        
        // Use the first row and coloumn as markers
        for(int i = 1; i < R; i++) {
            for(int j = 1; j < C; j++) {
                if(matrix[i][j] == 1) {
                    matrix[i][0] = 1;
                    matrix[0][j] = 1;
                }
            }
        }
        
        // Update the cells based on the markers
        for(int i = 1; i < R; i++) {
            for(int j = 1; j < C; j++) {
                if(matrix[i][0] == 1 || matrix[0][j] == 1) {
                    matrix[i][j] = 1;
                }
            }
        }
        
        // Update the first row if needed
        if(firstRowHasOne) {
            for(int j = 0; j < C; j++) {
                matrix[0][j] = 1;
            }
        }
        
        // Update the first column if needed
        if(firstColHasOne) {
            for(int i = 0; i < R; i++) {
                matrix[i][0] = 1;
            }
        }
    }
};