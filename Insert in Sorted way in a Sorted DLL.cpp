/*structure of the node of the DLL is as
struct Node {
    int data;
    struct Node* prev, *next;
};
*/
// function should insert a new node in sorted way in
// a sorted doubly linked list
// Return the head after insertion
class Solution {
  public:
    Node* sortedInsert(Node* head, int x) {
        
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = NULL;
        newNode->prev = NULL;
        
        if(head == NULL) {
            return newNode;
        }
        
        if(x <= head->data) {
            newNode->next = head;
            head->prev = newNode;
            return newNode;
        }
        
        Node* curr = head;
        
        while(curr->next && curr->next->data < x) {
            curr = curr->next;
        }
        
        newNode->next = curr->next;
        
        if(curr->next != NULL) {
            curr->next->prev = newNode;           
        }
        
        curr->next = newNode;
        newNode->prev = curr;
        
        return head;
    }
};