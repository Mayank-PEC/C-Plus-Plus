// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

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

class Solution
{
    public:
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        
       
    
    Node * fast =head;
    Node* slow=head;
    while(fast!=NULL)
    {
        if(fast->data<9)
          slow=fast;
          
          fast=fast->next;
    }
    
    if(slow==head)
    {
        if(slow->data<9)
        {
             slow->data++;
             slow=slow->next;
             while(slow!=NULL)
              {
                  slow->data=0;
                  slow=slow->next;
              }
        }
        else   //999
        {
            while(slow!=NULL)
             {
                 slow->data=0;
                 slow=slow->next;
             }
             Node* newnode=new Node(1);
             newnode->next=head;
             head=newnode;
        }
           
        
    }
    
    else
    {
    
        slow->data++;
        slow=slow->next;
        while(slow!=NULL)
        {
            slow->data=0;
            slow=slow->next;
        }

    }
    
    return head;
    
    
        
        
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends