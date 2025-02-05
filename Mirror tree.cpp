/* ------------------------------ Approach : Recursive Solution (DFS) ------------------------------ */
// Time Complexity : O(N)
// Space Complexity : O(H)


class Solution {
  public:
    void mirror(Node* node) {
       if(node == NULL) return;
        
        swap(node->left, node->right);
        
        mirror(node->left);
        mirror(node->right);
    }
};