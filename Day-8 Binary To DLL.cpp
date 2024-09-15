// This function should return head to the DLL
class Solution {
  public:
    void inOrder(Node* root, vector<Node*>& arr) {
        if(!root) return;
        
        inOrder(root->left, arr);
        arr.push_back(root);
        inOrder(root->right, arr);
    }
    
    Node* bToDLL(Node* root) {
        vector<Node*> arr;
        inOrder(root, arr);
        
        if(arr.size() == 1) {
            arr[0]->left = NULL;
            arr[0]->right = NULL;
            return arr[0];
        }
        
        for(int i = 0; i < arr.size(); i++) {
            if(i == 0) {  // First node
                arr[i]->left = NULL;
                arr[i]->right = arr[i+1];
            } 
            else if(i == arr.size() - 1) {  // last node
                arr[i]->right = NULL;
                arr[i]->left = arr[i-1];
            } 
            else {  // middle node
                arr[i]->left = arr[i-1];
                arr[i]->right = arr[i+1];
            }
        }
        return arr[0];
    }
};