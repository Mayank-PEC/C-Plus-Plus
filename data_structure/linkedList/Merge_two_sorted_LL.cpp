// { Driver Code Starts
#include<iostream>
using namespace std;



/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};






Node* sortedMerge(struct Node* a, struct Node* b);

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int data;
        cin>>data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin>>data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin>>data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for(int i=1; i<m; i++)
        {
            cin>>data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}





// } Driver Code Ends


 



/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/





//**************** function starts from here *****************************//
//Function to merge two sorted linked list.
Node* sortedMerge(Node* head1, Node* head2)  
{  
    // code here
    
    // it will make the result list 
    // starting from the node with the 
    //smallest value
     if(head1==NULL)
             return head2;
         if(head2==NULL)
             return head1;
    Node* i = head1;
    Node* j = head2;
    Node* result = NULL;
    Node* tail = NULL;
    while(i && j){
        
        if(i->data <=j->data){
            if(result==NULL){
                result = i;
            }
            if(tail==NULL){
                tail = result;
            }
            else{
                tail->next =i;
            tail = tail->next;
            }
            
            i=i->next;
            tail->next=NULL;
        }
        else
        {
            if(result==NULL){
                result = j;
            }
            if(tail==NULL){
                tail = result;
            }
            else{
                 tail->next =j;
                tail=tail->next;
            }
              
           
            j=j->next;
            tail->next=NULL;
        }
    }
    
    while(i!=NULL){
        tail->next= i;
        tail = tail->next;
        i=i->next;
        tail->next=NULL;
    }
    
    while(j!=NULL){
        tail->next = j;
        tail = tail->next;
        j=j->next;
        tail->next = NULL;
        
    }
    return result;
    
}  




