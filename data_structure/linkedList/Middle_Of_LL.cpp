 Node* middleNode(Node* head) {
        
   
        
        Node *fast = head , *slow = head;
        
        while(slow && fast && fast->next){
            fast = fast->next->next;
            slow=slow->next;
        }
        return slow;
    }