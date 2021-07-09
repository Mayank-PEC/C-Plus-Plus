// { Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}
// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
    
Node* sortedMerge(Node* head1, Node* head2)  
{  
    // code here
    
    // it will make the result list 
    // starting from the node with the 
    //smallest value
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
                tail->bottom =i;
            tail = tail->bottom;
            }
            
            i=i->bottom;
            tail->bottom=NULL;
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
                 tail->bottom =j;
                tail=tail->bottom;
            }
              
           
            j=j->bottom;
            tail->bottom=NULL;
        }
    }
    
    while(i!=NULL){
        tail->bottom= i;
        tail = tail->bottom;
        i=i->bottom;
        tail->bottom=NULL;
    }
    
    while(j!=NULL){
        tail->bottom = j;
        tail = tail->bottom;
        j=j->bottom;
        tail->bottom = NULL;
        
    }
    return result;
    
}  
/**********************************************************/
 void merge(Node** head,Node** start,Node** mid,Node** last){
    
    Node* L = NULL,*R = NULL,*ptr;
    ptr=*start;
    Node* temp;
    while(ptr!=(*mid)->bottom){
        
        if(L==NULL){
            L = new Node(ptr->data);
            temp = L;
        }
        else
        {
            temp->bottom = new Node(ptr->data);
            temp=temp->bottom;
        }
        ptr=ptr->bottom;
    }
    
    while(ptr!=(*last)->bottom){
        
        if(R==NULL){
            R = new Node(ptr->data);
            temp = R;
        }
        else
        {
            temp->bottom = new Node(ptr->data);
            temp=temp->bottom;
        }
        ptr=ptr->bottom;
    }

    Node* i = L;
    Node* j = R;
    Node* k = *start;
    while (i!=NULL && j!=NULL)
    {
        if (i->data <= j->data)
        {
            k->data = i->data;
            i=i->bottom;
        }
        else
        {
            k->data = j->data;
            j=j->bottom;
        }
        k=k->bottom;
    }

    while (i!=NULL)
    {
        k->data = i->data;
        i=i->bottom;
        k=k->bottom;
    }

    while (j!=NULL)
    {
        k->data = j->data;
        j=j->bottom;
        k=k->bottom;
    }
    
    
    
    }
    
    void FindMiddle(Node** start,Node** last,Node** mid){
        Node*slow = *start;
        Node*fast = *start;
        
        if(fast->bottom==*last){
             *mid = slow;
             return ;
        }
        
      
        
        while(fast && fast->bottom){
            
            fast=fast->bottom->bottom;
            slow=slow->bottom;
            
            if(fast==*last || fast->bottom==*last)
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
            mergesort(head,&mid->bottom,last);
            merge(head,start,&mid,last);
        }
    }
    Node* mergeSort(Node* head) {
        // your code here
    /***************Made by me *******************/
        Node* start = head , *last = head;
        while(last->bottom!=NULL)
          last=last->bottom;
        mergesort(&head,&start,&last);
        
        return head;
    }


/***********************************************************/

Node *flatten(Node *root)
{
   
/**********Using just the merge function of mergesort ***********/

   if(root==NULL)
     return NULL;
   
   if(root->next==NULL)
     return root;
     
    
    return sortedMerge(root,flatten(root->next));
    
    //the next pointer is not made null as the sorted function is applied on
    // the bottom pointer not the next pointer so there is no effect
    
/**********************************************************************/
    

/************this is done using proper conversion to linked list and 
    using merge sort  *********************/
   
//   Node* head1=root;
//   Node* head2 = root->next;
//   Node* final =root;
//   Node* travel;
   
//   while(head2!=NULL){
//       travel = head1;
//       while(travel->bottom!=NULL){
//           travel = travel->bottom;
           
//       }
//       travel->bottom = head2;
//       head1->next=NULL;
//       head1=head2;
//       head2=head2->next;
       
//   }
   
   
//   return mergeSort(final);
   
   
   
}
