/*
Structure of linked list is as
struct Node
{
    int data;
    struct Node* npx;

    Node(int x){
        data = x;
        npx = NULL;
    }
};

Utility function to get XOR of two Struct Node pointer
use this function to get XOR of two pointers
struct Node* XOR (struct Node *a, struct Node *b)
{
    return (struct Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}
*/

// function should insert the data to the front of the list
struct Node *insert(struct Node *head, int data) {
    Node* newNode = new Node(data);
    newNode->npx = head;
    
    if(head) {
        head->npx = XOR(newNode, head->npx);
    }
    return newNode;
}

vector<int> getList(struct Node *head) {
    Node* curr = head;
    Node* prev = NULL, *next;
    
    vector<int> result;
    
    while(curr) {
        result.push_back(curr->data);
        next = XOR(prev, curr->npx);
        prev = curr;
        curr = next;
    }
    return result;
}
