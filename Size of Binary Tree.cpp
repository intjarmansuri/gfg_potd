/* ----------- Approach 1 -----------*/

/*
Definition for Binary Tree Node
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

class Solution {
  public:
    
    void total(Node* root, int &count) {
        if(root == NULL) {
            return;
        }
        
        count++;
        total(root->left, count);
        total(root->right, count);
    }  
  
    int getSize(Node* root) {
        
        int count = 0;
        total(root, count);
        return count;
    }
};


/* --------- Approach 2 -------------- */

/*
Definition for Binary Tree Node
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

class Solution {
  public:
    
    void total(Node* root, int &count) {
        if(root == NULL) {
            return;
        }
        
        count++;
        total(root->left, count);
        total(root->right, count);
    }  
  
    int getSize(Node* root) {
        
        int count = 0;
        total(root, count);
        return count;
    }
};