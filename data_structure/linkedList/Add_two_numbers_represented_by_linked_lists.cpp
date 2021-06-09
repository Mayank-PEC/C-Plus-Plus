// { Driver Code Starts
// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
/*int carry_fuct(Node* first,Node* second)
{
    if(first->next==NULL && second->next==NULL)
      return (first->data+second->data);
      
      int res=first->data
}*/

int length(Node* head)
{
    int len=0;
    Node* ptr=head;
    while(ptr!=NULL)
     {
         len++;
         ptr=ptr->next;
     }
     
     return len;
}

Node* reverse(Node* head)
{
    Node* nxt = NULL;
    Node* prev=NULL;
    Node* curr=head;
    
    while(curr!=NULL)
    {
        nxt = curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }
    return prev;
}

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        //int carry=carry_fuct(first,second);


    int len1=0,len2=0;
   
    len1 = length(first);
    first = reverse(first);
   
    len2 = length(second);
    second = reverse(second);
    
    
    
    int val;
    int carry=0;
    Node* x=first;
    Node* y=second;
    if(len1>=len2)
    {
        while(y!=NULL)
    {
        val=x->data+y->data+carry;
        carry=val/10;
        x->data=val%10;
        y=y->next;
        x=x->next;
    }
    
    while(carry && x!=NULL)
    {
      val=x->data+carry;
      carry=val/10;
      x->data=val%10;
      x=x->next;
        
    }
    
    if(carry)
    {
         x=first;
         while(x->next!=NULL)
           x=x->next;
         x->next=new Node(carry);
    }
    
    first = reverse(first);
    return first;
    
    }
   
    else
    {
        while(x!=NULL)
    {
        val=x->data+y->data+carry;
        carry=val/10;
        y->data=val%10;
        y=y->next;
        x=x->next;
    }
    
    while(carry && y!=NULL)
    {
      val=y->data+carry;
      carry=val/10;
      y->data=val%10;
      y=y->next;
        
    }
    
    if(carry)
    {
         y=second;
         while(y->next!=NULL)
           y=y->next;
         y->next=new Node(carry);
    }
    
    second = reverse(second);
    return second;
    
    }
    
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends