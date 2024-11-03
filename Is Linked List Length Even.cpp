/* --------------- Approach : Simple LL Traverse and Count the node ------------ */
// Time Complexity : O(N)
// Space Complexity : O(1)

class Solution {
  public:
    bool isLengthEven(struct Node **head) {
        int count = 0;
        Node* curr = *head;
        
        // Traverse the linked list to count the nodes
        while (curr) {
            count++;
            curr = curr->next;
        }
        
        // Check if the count is even or odd
        return (count % 2 == 0);
    }
};