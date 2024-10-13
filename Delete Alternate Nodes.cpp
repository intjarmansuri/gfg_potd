/*
Structure of the node of the binary tree
struct Node
{
    int data;
    struct Node *next;

    Node(int x){
        int data = x;
        next = NULL;
    }
};
*/
// Complete this function
class Solution {
  public:
    void deleteAlt(struct Node *head) {
        
        if(head == NULL || head->next == NULL) {
            return;
        }
        
        Node *curr = head;
        
        while(curr && curr->next) {
            Node *temp = curr->next;
            curr->next = temp->next;
            delete temp;
            curr = curr->next;
        }
    }
};