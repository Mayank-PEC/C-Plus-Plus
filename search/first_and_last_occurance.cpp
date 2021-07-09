#include<bits/stdc++.h>
using namespace std;
vector<int> find(int a[], int n , int x );

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}




vector<int> find(int arr[], int n , int x )
{
    // code here
    
          int s=0;
          int h=n-1;
          int res=-1;
          vector<int> ans;
          while(s<=h)
          {
              int mid=(s+(h-s)/2);
              
              if(arr[mid]==x)
              {
                  res=mid;
                  
                  if(mid>=1 && arr[mid]!=arr[mid-1])
                     break;
                     
             //toggle variable 
            // can be used see code library
                  h=mid-1;
              }
              
              else if(arr[mid]>x)
                 h=mid-1;
                 
            else
               s=mid+1;
                
          }
          
          ans.push_back(res);
          
          res=-1;
          s=0;
          h=n-1;
           while(s<=h)
          {
              int mid=(s+(h-s)/2);
              
              if(arr[mid]==x)
              {
                  res=mid;
                
                  
                  if(mid+1<n && arr[mid]!=arr[mid+1])
                     break;
                     
                     s=mid+1;       //toggle variable 
                                    // can be used see code library
              }
              
              else if(arr[mid]>x)
                 h=mid-1;
                 
            else
               s=mid+1;
                
          }
          
          ans.push_back(res);
          
          
          return ans;
          
          
          
          
          
          
          
          
          
          
          
          
          
}