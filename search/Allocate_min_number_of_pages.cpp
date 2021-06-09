// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution {
  public:
  
    bool isValid(int arr[],int n,int m,int k)
    {
        int stud=1;
        int sum=0;
        
        for(int i=0;i<n;i++)
        {
           
            
            if(arr[i]>k)
              return false;
            
            if(sum>k)
            {
                stud++;
                sum=arr[i];
                
                if(stud>m)
                  return false;
            } 
            else 
               sum+=arr[i];
            
        }
        
        return true;
    }
    int findPages(int arr[], int n, int m) {
        //code here
        
        if(n<m)
          return -1;
          
          int l=INT_MIN;
          int h=0;
         for(int i=0;i<n;i++)
         {
             h+=arr[i];
             l=max(l,arr[i]);
         }
            
            int res=INT_MAX;
        while(l<=h)
        {
            int mid=(l+h)/2;
            
            if(isValid(arr,n,m,arr[mid])==true)
            {
                res=min(res,mid);
                h=mid-1;
            }
            else 
                l=mid+1;
        }
        
        
        return res;
            
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends