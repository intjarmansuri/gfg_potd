/* ----------------------- Approach : Two Pointer Technique -------------------------- */
// Time Complexity : O(N)
// Space Complexity : O(1)

class Solution {
  public:
    int getKthFromLast(Node *head, int k) {
       if(!head) {
           return -1;
       }
       
       Node* first = head;
       Node* second = head;
       
       for(int i = 0; i < k; i++) {
           if(!first) {
               return -1;
           }
           
           first = first->next;
       }
       
       while(first) {
           first = first->next;
           second = second->next;
       }
       
       return second->data;
    }
};