/* ------------- Approach 1 : Using PreOrder Travsersal ---------- */

/*Structure of the node of the binary tree
struct Node
{
	int key;
	Node* left, *right;
};
*/

void totalSum(Node* root, long int& sum) {
    if(root == NULL) {
        return;
    }
    
    sum += root->key;
    totalSum(root->left, sum);
    totalSum(root->right, sum);
}

long int sumBT(Node* root)
{
    long int sum = 0;
    
    totalSum(root, sum);
    
    return sum;
}


/* ------------- Approach 2 : ---------- */

/*Structure of the node of the binary tree
struct Node
{
	int key;
	Node* left, *right;
};
*/

long int sumBT(Node* root)
{
    if(root == NULL) {
        return 0;
    }
    
    return (root->key + sumBT(root->left) + sumBT(root->right));
}