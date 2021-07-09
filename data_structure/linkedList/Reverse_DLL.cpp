// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};

Node *newNode(int data)
{
    Node *temp=new Node(data);
    
    return temp;
}




void displayList(Node *head)
{
    //Head to Tail
    while(head->next)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<head->data;
    
    
    
}


int getLength(Node * head)
{
    Node *temp=head;
    
    int count=0;
    while(temp->next!=head)
    {
        count++;
        temp=temp->next;
    }
    return count+1;
}




bool verify(Node* head)
{
    int fl=0;
    int bl=0;
    
    Node *temp=head;
    
    while(temp->next)
    {
        temp=temp->next;
        fl++;
    }
    
    while(temp->prev)
    {
        temp=temp->prev;
        bl++;
    }
    
    return fl==bl;
}


 // } Driver Code Ends
/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};
*/

void reverse(Node* head){
     
    Node* current=head;
    Node* Next=NULL;
    while(current!=NULL)
    {  
        Next = current->next;
        current->next = current->prev;
        current->prev = Next;
        current = Next;
    
    }
      
}

void reverse1(Node* head){
     
    Node* current=head;
    Node* Next=NULL;
    while(current!=NULL)
    {  
        Next = current->prev;
        current->prev = current->next;
        current->next = Next;
        current = Next;
    
    }
      
}


Node* reverseDLL(Node * head)
{
    
    /********method1 ************/
    // here i used reverse function
    // reverse(head);
    // Node* curr = head;
    // while(curr->prev!=NULL){
    //     curr=curr->prev;
    // }
    // head = curr;
    
    // return head;
    



    /*********method 2****************/
    // here i used reverse 1 function
    Node* curr = head;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    head = curr;
    reverse1(head);
    return head;
    
    
}









// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    Node *head=NULL, *tail=NULL;
        int x;
	    cin>>x;
	    head = newNode(x);
	    tail = head;
	    
	    for(int i=0;i<n - 1;i++)
	    {
	        cin>>x;
	        Node* temp=newNode(x);
	        tail->next=temp;
	        temp->prev= tail;
	        tail = temp;
	    }
	    head=reverseDLL(head);
	    
	    
	    if(verify(head))
	    displayList(head);
	    else
	    cout<<"Your pointers are not correctly connected";
 
	    cout<<endl;
	}
	return 0;
}

  // } Driver Code Ends