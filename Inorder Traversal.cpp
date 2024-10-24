/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; */

class Solution {
  public:
    
    void inorderTraversal(Node* root, vector<int>& result) {
        
        if(root == NULL) {
            return;
        }
        
        inorderTraversal(root->left, result);
        
        result.push_back(root->data);
        
        inorderTraversal(root->right, result);
    }
  
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        
        vector<int> result;
        
        inorderTraversal(root, result);
        
        return result;
    }
};