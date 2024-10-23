/* ------ Approach 1: Calculate Total Length and Then Traverse Again ------ */

class Solution {
  public:
    /*Structure of the node of the linled list is as

    struct Node {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }
    };
    */
    
    int sumOfLastN_Nodes(struct Node* head, int n) {
        Node* temp = head;
        int length = 0;
        
        // Step 1: Calculate total length of the linked list
        while(temp) {
            length++;
            temp = temp->next;
        }
        
        // Step 2: Traverse till (totalLength - n) nodes and calculate sum of last n nodes
        int skipLength = length  - n;
        temp = head;
        for(int i = 0; i < skipLength; i++) {
            temp = temp->next;
        }
        
        // Now temp is at the position from where we start summing the last n nodes
        int sum = 0;
        while(temp) {
            sum += temp->data;
            temp = temp->next;
        }
        
        return sum;
    }
};


/* ------ Approach 2: Reverse the Linked List and Sum the First N Nodes ------ */

class Solution {
  public:
    /*Structure of the node of the linled list is as

    struct Node {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }
    };
    */
    
    // Function to reverse the linked list
    Node* reverseList(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        
        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    int sumOfLastN_Nodes(struct Node* head, int n) {
        
        // Step 1: Reverse the linked list
        head = reverseList(head);
        
        // Step 2: Calculate sum of the first n nodes
        int sum = 0;
        Node* temp = head;
        for(int i = 0; i < n; i++) {
            if(temp) {
                sum += temp->data;
                temp = temp->next;
            }
        }
        return sum;
    }
};

/* ------ Approach 3: Two Pointers Approach (Efficient Solution) ------ */

class Solution {
  public:
    /*Structure of the node of the linled list is as

    struct Node {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }
    };
    */
 
    int sumOfLastN_Nodes(struct Node* head, int n) {
        Node* fast = head;
        Node* slow = head;
        
        // Move 'fast' n nodes ahead
        for(int i = 0; i < n; i++) {
            fast = fast->next;
        }
        
        // Move 'fast' to the end and 'slow' n nodes behind
        while(fast) {
            fast = fast->next;
            slow = slow->next;
        }
        
         // Calculate the sum of the last n nodes
        int sum = 0;
        while(slow) {
            sum += slow->data;
            slow = slow->next;
        }
        return sum;
    }
};