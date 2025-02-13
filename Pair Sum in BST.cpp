// Approach-1 (Brutforce - Inorder Traversal)
// T.C : O(N^2)
// S.C : O(N)

class Solution {
  public:
    void inOrder(Node* root, vector<int>& vec) {
        if(root == NULL) return;
        
        inOrder(root->left, vec);
        vec.push_back(root->data);
        inOrder(root->right, vec);
    }
    
    bool findTarget(Node *root, int target) {
        vector<int> vec;
        inOrder(root, vec);
        
        int n = vec.size();
        for(int i = 0; i < n; i++) {
            
            for(int j = i+1; j < n; j++) {
                if(vec[i] + vec[j] == target) {
                    return  true;
                }
            }
        }
        return false;
    }
};

// Approach-2 (Two Pointer - Inorder Traversal)
// T.C : O(N)
// S.C : O(N)

class Solution {
  public:
    void inOrder(Node* root, vector<int>& vec) {
        if(root == NULL) return;
        
        inOrder(root->left, vec);
        vec.push_back(root->data);
        inOrder(root->right, vec);
    }
    
    bool findTarget(Node *root, int target) {
        vector<int> vec;
        inOrder(root, vec);
        
        int n = vec.size();
        int i = 0;
        int j = n-1;
       
        while(i < j) {
            
            if(vec[i] + vec[j] == target) {
                return true;
            }
            else if(vec[i] + vec[j] > target) {
                j--;
            }
            else {
                i++;
            }
        }
        return false;
    }
};

// Approach-3 (HashSet - Inorder Traversal)
// T.C : O(N)
// S.C : O(N)

class Solution {
  public:
    bool findPair(Node* root, unordered_set<int>& seen, int target) {
        if(root == NULL) return false;
        
        if(findPair(root->left, seen, target)) return true;
        
        if(seen.find(target - root->data) != seen.end()) {
            return true;
        }
        seen.insert(root->data);
        
        return findPair(root->right, seen, target);
    }
    
    bool findTarget(Node *root, int target) {
        
        unordered_set<int> seen;
        
        return findPair(root, seen, target);
    }
};