class Solution {
public:
    Node* copyList(Node* head) {
        if (head == NULL) return NULL;

        // Step 1: Create new nodes and interleave them with original nodes
        Node* temp = head;
        while (temp != NULL) {
            Node* newNode = new Node(temp->data); 
            newNode->next = temp->next; 
            temp->next = newNode; 
            temp = newNode->next;
        }

        // Step 2: Set the random pointers for the new nodes
        temp = head;
        while (temp != NULL) {
            if (temp->random != NULL) {
                temp->next->random = temp->random->next; 
            }
            temp = temp->next->next;
        }

        // Step 3: Separate the copied list from the original list
        temp = head;
        Node* newHead = head->next; 
        Node* copyTemp = newHead;
        
        while (temp != NULL) {
            temp->next = temp->next->next;  
            if (copyTemp->next != NULL) {
                copyTemp->next = copyTemp->next->next;  
            }
            temp = temp->next;  
            copyTemp = copyTemp->next; 
        }

        return newHead;
    }
};