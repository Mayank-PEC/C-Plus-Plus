#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};


/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/

class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {


        /* this method uses only two pointers --> */
     
     /*  
      void reverse(struct Node** head_ref)
{
    struct Node* current = *head_ref;
    struct Node* next;
    while (current->next != NULL) {
        next = current->next;
        current->next = next->next;
        next->next = (*head_ref);
        *head_ref = next;
    }
}   

*/
 



        
   /* *************iterative approach ******************/   

      /**********************
      Node* ptr=head;
    Node* current=head;
    Node* Next;
    Node* prev=NULL;
    while(current!=NULL)
    {                             //iterative approach....
        Next=current->next;
        current->next=prev;
        prev=current;
        current=Next;
    }
       return prev;
       
    *********************************/


   //recursive approach ...

    if(head==NULL  || head->next==NULL)
    {
        return head;
    }
      
    
    Node*  rest=reverseList(head->next);
    head->next->next=head;
    head->next=NULL;
    return rest;
    }


    
};
    

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
       printf("%d ", temp->data);
       temp  = temp->next;
    }
}


int main()
{
    int T,n,l,firstdata;
    cin>>T;

    while(T--)
    {
        struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        
        for (int i=1; i<n; i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        
        Solution ob;
        head = ob. reverseList(head);
        
        printList(head);
        cout << endl;
    }
    return 0;
}


