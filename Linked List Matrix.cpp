/*
struct Node
{
    int data;
    Node* right, *down;

    Node(int x){
        data = x;
        right = NULL;
        down = NULL;
    }
};
*/

// function must return the pointer to the first element of the in linked list i.e. that
// should be the element at arr[0][0]
class Solution {
  public:
    Node* constructLinkedMatrix(vector<vector<int>>& mat) {
        
        int n = mat.size();
        
        if(n == 0) return NULL;
        
        vector<vector<Node*>> matLL(n, vector<Node*> (n, NULL));
        
        for(int i = 0; i < n; i++) {
            
            for(int j = 0; j < n; j++) {
                matLL[i][j] = new Node(mat[i][j]);
            }
        }
        
        for(int i = 0; i < n; i++) {
            
            for(int j = 0; j < n; j++) {
                
                if(j < n-1) {
                    matLL[i][j]->right = matLL[i][j+1];
                }
                
                if(i < n-1) {
                    matLL[i][j]->down = matLL[i+1][j];
                }
            }
        }
        return matLL[0][0];
    }
};