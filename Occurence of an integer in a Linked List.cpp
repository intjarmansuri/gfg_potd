/* ---------------- Approach : Using Linear Saerch ---------------- */
// Time Complexity : O(N)
// Space Complexity : O(1)


class Solution {
  public:
    int count(struct Node* head, int key) {
        
        int count = 0;
        Node* curr = head;
        
        while(curr) {
            
            if(curr->data == key) {
                count++;
                curr = curr->next;
            } else {
                curr = curr->next;
            }
        }
        
        if(curr == NULL && count == 0) {
            return 0;
        }
        return count;
    }
};