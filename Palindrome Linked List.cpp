class Solution {
  public:
    Node* reverseLL(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        
        while(curr != NULL) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    bool isPalindrome(Node* head) {
        if(!head || !head->next) return true;
        
        Node* slow = head;
        Node* fast = head;
        
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        };
        
        Node* secondHalf = reverseLL(slow);
        Node* firstHalf = head;
        
        while(secondHalf != NULL) {
            if(firstHalf->data != secondHalf->data) {
                return false;
            }
            secondHalf = secondHalf->next;
            firstHalf = firstHalf->next;
        }
        return true;
    }
};