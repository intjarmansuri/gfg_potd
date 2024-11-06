/* -------------------- Approach : Using DFS ------------------*/
// Time Complexity : O(N)
// Space Complexity : O(H)

class Solution
{
    public:
     void dfs(Node* root, int level, vector<int>& result) {
         if(root == NULL) {
            return;
         }
         
         if(result.size() < level) {
             result.push_back(root->data);
         }
         
         dfs(root->right, level+1, result);
         dfs(root->left, level+1, result);
     }
    
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       vector<int> result;
       dfs(root, 1, result);
       return result;
    }
};