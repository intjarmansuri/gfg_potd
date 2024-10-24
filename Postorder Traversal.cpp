/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}; */

void postorderTraversal(Node* root, vector<int>& result) 
{
    if(root == NULL) {
        return;
    }
    
    postorderTraversal(root->left, result);
    postorderTraversal(root->right, result);
    
    result.push_back(root->data);
}

//Function to return a list containing the postorder traversal of the tree.
vector <int> postOrder(Node* root)
{
  vector<int> result;
  
  postorderTraversal(root, result);
  
  return result;
}