/* ------------------- Approach : Slow Fast Pointer (floyd's Cycle Detection) ------------------- */
// Time Complexity : O(N)
// Space Complexity : O(1)


class Solution {
  public:
    Node* findFirstNode(Node* head) {
        if(!head || !head->next) return NULL;
        
        Node* slow = head;
        Node* fast = head;
        
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast) {
                
                slow = head;
                while(slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};