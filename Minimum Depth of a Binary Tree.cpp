/* -------------------- Approach : Using DFS ------------------*/
// Time Complexity : O(N)
// Space Complexity : O(H)

class Solution{
  public:
    /*You are required to complete this method*/
    int minDepth(Node *root) {
        if(root == NULL) {
            return 0;
        }
        
        if(root->left == NULL && root->right == NULL) {
            return 1;
        }
        
        if(root->left == NULL) {
            return 1 + minDepth(root->right);
        }
        
        if(root->right == NULL) {
            return 1 + minDepth(root->left);
        }
        
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};

/* -------------------- Approach : Using BFS ------------------*/
// Time Complexity : O(N)
// Space Complexity : O(N)

class Solution{
  public:
    /*You are required to complete this method*/
    int minDepth(Node *root) {
        if(root == NULL) {
            return 0;
        }
        
        queue<pair<Node*, int>> que;
        que.push({root, 1});
        
        while(!que.empty()) {
            auto curr = que.front();
            que.pop();
            
            Node* node = curr.first;
            int  depth = curr.second;
            
            // Check if we have reached a leaf node
            if(node->left == NULL && node->right == NULL) {
                return depth; // Return the depth when the first leaf node is found
            }
            
            if(node->left) {
                que.push({node->left, depth+1});
            }
            
            if(node->right) {
                que.push({node->right, depth+1});
            }
        }
        return 0;
    }
};