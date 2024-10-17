struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) {
        
        Node* listA = new Node(0);
        Node* listB = new Node(0);
        Node* currA = listA;
        Node* currB = listB;
        
        int index = 0;
        
        while(head) {
            
            if(index % 2 == 0) {
                currA->next = head;
                currA = currA->next;
            } else {
                currB->next = head;
                currB = currB->next;
            }
            
            head = head->next;
            index++;
        }
        currA->next = NULL;
        currB->next = NULL;
        
        return {listA->next, listB->next};
    }
};