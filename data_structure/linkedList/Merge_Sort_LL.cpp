// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    
    void merge(Node** head,Node** start,Node** mid,Node** last){
    
    Node* L = NULL,*R = NULL,*ptr;
    ptr=*start;
    Node* temp;
    while(ptr!=(*mid)->next){
        
        if(L==NULL){
            L = new Node(ptr->data);
            temp = L;
        }
        else
        {
            temp->next = new Node(ptr->data);
            temp=temp->next;
        }
        ptr=ptr->next;
    }
    
    while(ptr!=(*last)->next){
        
        if(R==NULL){
            R = new Node(ptr->data);
            temp = R;
        }
        else
        {
            temp->next = new Node(ptr->data);
            temp=temp->next;
        }
        ptr=ptr->next;
    }

    Node* i = L;
    Node* j = R;
    Node* k = *start;
    while (i!=NULL && j!=NULL)
    {
        if (i->data <= j->data)
        {
            k->data = i->data;
            i=i->next;
        }
        else
        {
            k->data = j->data;
            j=j->next;
        }
        k=k->next;
    }

    while (i!=NULL)
    {
        k->data = i->data;
        i=i->next;
        k=k->next;
    }

    while (j!=NULL)
    {
        k->data = j->data;
        j=j->next;
        k=k->next;
    }
    
    
    
    }
    
    void FindMiddle(Node** start,Node** last,Node** mid){
        Node*slow = *start;
        Node*fast = *start;
        
        if(fast->next==*last){
             *mid = slow;
             return ;
        }
        
      
        
        while(fast && fast->next){
            
            fast=fast->next->next;
            slow=slow->next;
            
            if(fast==*last || fast->next==*last)
               {
                   *mid = slow;
                   return ;
               }
        }
        
        
    }
    void mergesort(Node** head,Node** start ,Node** last){
        if(*start != *last){
            Node* mid = NULL;
            FindMiddle(start,last,&mid);
            
            mergesort(head,start,&mid);
            mergesort(head,&mid->next,last);
            merge(head,start,&mid,last);
        }
    }
    Node* mergeSort(Node* head) {
        // your code here
    /***************Made by me *******************/
        Node* start = head , *last = head;
        while(last->next!=NULL)
          last=last->next;
        mergesort(&head,&start,&last);
        
        return head;
    }
};


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends


