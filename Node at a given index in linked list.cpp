/* -------------- Approach Traverse LL and Count comapre with index ------------- */
// Time Complexity : O(N)
// Space Complexity : O(1)


class Solution {
  public:
    int GetNth(Node *head, int index) {
        
        Node* curr = head;
        int count = 1;
        
        while(curr != NULL) {
            
            if(count == index) {
                return curr->data;
            }
            
            curr = curr->next;
            count++;
        }
        return -1;
    }
};