class Solution {
  public:
    void inOrder(Node* root, vector<int>& arr) {
        if(root == NULL) return;
        
        inOrder(root->left, arr);
        arr.push_back(root->data);
        inOrder(root->right, arr);
    }
    
    vector<int> merged(vector<int>& arr1, vector<int>& arr2) {
        vector<int> result;
        
        int i = 0, j = 0;
        
        while(i < arr1.size() && j < arr2.size()) {
            if(arr1[i] < arr2[j]) {
                result.push_back(arr1[i]);
                i++;
            } else {
                result.push_back(arr2[j]);
                j++;
            }
        }
        
        while(i < arr1.size()) {
            result.push_back(arr1[i]);
            i++;
        }
        
        while(j < arr2.size()) {
            result.push_back(arr2[j]);
            j++;
        }
        return result;
    }
    
    vector<int> merge(Node *root1, Node *root2) {
        vector<int> arr1, arr2;
        inOrder(root1, arr1);
        inOrder(root2, arr2);
        
        return merged(arr1, arr2);
    }
};