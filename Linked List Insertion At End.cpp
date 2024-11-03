/* -------------- Approach Traverse LL and InertionAtEnd ------------- */
// Time Complexity : O(N)
// Space Complexity : O(1)


class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        
        // Check if the list is initially empty
        if (head == NULL) {
            Node* newNode = new Node(x);
            newNode->next = NULL;
            return newNode;
        }
        
        Node* curr = head;
        
        // Traverse to the end of the list
        while (curr->next) {
            curr = curr->next;
        }
        
        // Create and attach the new node
        Node* newNode = new Node(x);
        curr->next = newNode;
        newNode->next = NULL;
        
        return head;
    }
};