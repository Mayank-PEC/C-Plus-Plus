// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




 // } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    Node* FindMin(Node* head){
        
        
         Node *fast = head->next , *slow = head;
        
        while(slow && fast && fast->next){
            fast = fast->next->next;
            slow=slow->next;
        }
        return slow;
        
        
    }
    Node* reverse(Node* head){
        
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
    }
    
    bool solve(Node** left,Node* right){
        
         if(right->next==NULL){
             if(right->data == (*left)->data)
             {
                 *left = (*left)->next;
                  return 1;
             }
                
            return 0;
         }
    
    
         if(solve(left,right->next) && (*left)->data == right->data)
         {
             *left = (*left)->next;
             return 1;
         }
           
           
           return 0;
    
        
    }

    
    bool isPalindrome(Node *head)
    {
    
        /**********iterative solution ************/
     /*   Node* mid = FindMin(head);
          mid->next = reverse(mid->next);
        
        Node* first = head;
        Node* second = mid->next;
        
        while(second!=NULL){
            if(first->data!=second->data)
                return 0;
            first=first->next;
            second=second->next;
        }
        
        return 1;
        */
 
   /***********recursive solution *********************/
        return solve(&head,head);


    }
    
    
// Another way could be(This is a method using only single iteration):
// 1. Add to the top of stack till the mid of the linked list is 
// reached(using fast and slow).
// 2. If fast.next is null then:
// a) Until the stack is empty do:
// i) pop from stack check against slow
// ii) slow = slow.next
// 3. else
// a) slow = pop()
// b) Until the stack is empty do:
// i) pop from the stack check against slow
// ii) slow = slow.next    
// };

// fast and slow ptr concept.push slow ptr elements 
// into stack and when fastptr reaches null it means 
// odd no of elements , so pop element,and then continue 
// to pop until stack is empty or list is empty,may be this vague idea





// { Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}

  // } Driver Code Ends