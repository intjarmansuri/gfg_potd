/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution
{
    public:
    void levelOrderTraversal(Node* root, vector<int>& result) 
    {
        if(root == NULL) {
            return;
        }
        
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty()) {
            int n = q.size();
            
            for(int i = 0; i < n; i++) {
                Node* curr = q.front();
                q.pop();
                
                result.push_back(curr->data);
                
                if(curr->left) {
                    q.push(curr->left);
                }
                if(curr->right) {
                    q.push(curr->right);
                }
            }
        }
    }
    
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* root)
    {
      vector<int> result;
      
      levelOrderTraversal(root, result);
      
      return result;
    }
};