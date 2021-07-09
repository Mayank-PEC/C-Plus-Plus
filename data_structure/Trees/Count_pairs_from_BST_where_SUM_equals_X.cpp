// { Driver Code Starts
// C++ implementation to count pairs from two
#include <bits/stdc++.h>
using namespace std;

// structure of a node of BST


struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};




void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}



int countPairs(Node* root1, Node* root2, int x);



// Driver code
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node* root1 = NULL;
        Node* root2 = NULL;
        int n1, n2, k;
        cin>>n1;
        for(int i=0; i<n1; i++)
        {
            cin>>k;
            insert(&root1, k);
        }
        cin>>n2;
        for(int i=0; i<n2; i++)
        {
            cin>>k;
            insert(&root2, k);
        }
        int s;
        cin>>s;
        cout<<countPairs(root1, root2, s)<<"\n";
    }
    return 0;
}




// } Driver Code Ends


//User function Template for C++
/*Structure of the Node of the BST is as
struct Node {
	int data;
	Node* left, *right;
};*/
// You are required to complete this function




void inorder(Node* root,vector<int> &v)
{
    if(root!=NULL)
    {
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
    
    return ;
}





int countPairs(Node* root1, Node* root2, int x)
{
    // Code here
    
  /**************************************
   // recursive.....but not working
  if(root1==NULL || root2==NULL)
      return 0;
      
     if(root1->data+root2->data==x)
       return 1;
       
       
     int right=0,left=0;
     if(x-root1->data>root2->data)
     {
          right+=countPairs(root1,root2->right,x)+count(root1->right,root2,x);
     }
     
     else   
     {
          left+=countPairs(root1,root2->left,x)+count(root1->left,root2,x);
     }
     
    return left+right;
     
     *****************************************/
     
     if(root1==NULL || root2==NULL)
       return 0;
        
     vector<int> v1,v2;
     
     inorder(root1,v1);
     inorder(root2,v2);
     int cnt=0;
     int i=0;
     int j =v2.size()-1;
     int n = v1.size();
    
     while(i<n && j>=0)
     {
         if(v1[i]+v2[j]==x)
         {
             cnt++;
             j--;
             i++;
         }
         else if(v1[i]+v2[j]>x)
         {
             j--;
         }
         else
            i++;
     }
     
     
     return cnt;
     


     
// for space optimization can be done by 
// converting both the tree 
// into Doubly linked list and then 
// traversing one from 
// start and one from end.
// Time complexity will be O(n1+n2)
     



//  O(1) space and O(n) time solution:
// 1. Convert the trees into doubly linked lists in place.
// 2. Traverse one from starting and one 
// from end to get the ans.
// (This solution can't convert back the BSTs 
// to their original structure).       
    
}









