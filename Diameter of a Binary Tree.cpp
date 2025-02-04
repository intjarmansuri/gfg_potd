/* ------------------------ Approach : DFS ( PostOrder) --------------------------*/
// Time Complexity : O(N)
// Space Complexity : O(1)

class Solution {
  public:
    int dfs(Node* root, int &maxDiameter) {
        if(!root) return 0;
        
        int leftHt = dfs(root->left, maxDiameter);
        int rightHt = dfs(root->right, maxDiameter);
        
        maxDiameter = max(maxDiameter, leftHt + rightHt);
        
        return 1 + max(rightHt, leftHt);
    }
    int diameter(Node* root) {
        int maxDiameter = 0;
        dfs(root, maxDiameter);
        return maxDiameter;
    }
};