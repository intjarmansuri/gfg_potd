/* -------------------- Approach : Using DFS ------------------*/
// Time Complexity : O(N)
// Space Complexity : O(H)

class Solution {
  public:
    int dfs(Node* node, int currNum) {
        if(node == NULL) {
            return 0;
        }
        
        currNum = 10*currNum + node->data;
        
        if(node->left == NULL && node->right == NULL) {
            return currNum;
        }
        
        int leftSum = dfs(node->left, currNum);
        int rightSum = dfs(node->right, currNum);
        
        return leftSum + rightSum;
    }
    int treePathsSum(Node *root) {
        
        return dfs(root, 0);
    }
};