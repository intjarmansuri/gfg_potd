

class Solution {
  public:
    void inorder(Node* root, int& k, int& result) {
        if (root == NULL) return;
    
        inorder(root->left, k, result);
    
        k--;
        if (k == 0) { 
            result = root->data;
            return;
        }
    
        inorder(root->right, k, result);  
    }
    int kthSmallest(Node *root, int k) {
        int result = -1;
        inorder(root, k, result);
        return result;
    }
};