// Time Complexity : O(N)
// Space Complexity : O(1)

class Solution {
  public:
    Node* rotate(Node* head, int k) {
        if(!head || k == 0) return head;
        
        // Step 1 : Find the length of linked list
        Node* temp = head;
        int length = 1;
        while(temp->next) {
            temp = temp->next;
            length++;
        }
        
        // Normalize K
        k = k % length;
        if(k == 0) return head;
        
        // Step 2 : Traverse to the kth node
        temp = head;
        int count = 1;
        while(count < k) {
            temp = temp->next;
            count++;
        }
        
        // Step 3 : Split linked list into two parts
        Node* newHead = temp->next;
        temp->next = NULL;
        
        // Step 4 : Attach of the list to the old head;
        Node* tail = newHead;
        while(tail->next) {
            tail = tail->next;
        }
        tail->next = head;
        
        return newHead;
    }
};
