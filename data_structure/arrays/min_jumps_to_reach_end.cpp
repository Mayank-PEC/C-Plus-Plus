// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
  
  int solve_using_arrays(int arr[],int n)
  {
          if(n<=1)
     return -1;
     
    if(arr[0]==0)
      return -1;
      
    int stairs=arr[0];
    int ladder=arr[0];
    int jump=1;
    for(int i=1;i<n;i++)
    {
        if(i==n-1)
          return jump;
        
          
        if(i+arr[i]>ladder)
          ladder=i+arr[i];
          
         stairs--;
         
         if(stairs==0)
         {
             jump++;
             
             if(i>=ladder)  //we are not able to find a big ladder now...
               return -1;
             
             stairs=ladder-i;
         }
          
    }
    return jump;
    }
    
    int dp_solution_bottom_up(int arr[],int n)
    {
        
        // exceeds the time limit.... TLE
        int dp[n];
        
        dp[0]=0;
        
        
        
        for(int i=1;i<n;i++)
        {
            dp[i]=INT_MAX;
            for(int j=0;j<i;j++)
            {
                if(dp[j]==INT_MAX)
                  continue;
    // dp[j]==INT_MAX means if we can't reach j then 
     // how can we reach i....
     
     
                else if(j+arr[j]>=i)
                {
                    if(dp[j]+1<dp[i])
                      dp[i]=1+dp[j];
                }
            }
        }
        
       /* for(int i=0;i<n;i++)
          cout<<dp[i]<<" ";
          
          cout<<"\n";*/
        
        if(dp[n-1]==INT_MAX)
          return -1;
          
         else return dp[n-1];
        
    }
  
    int minJumps(int arr[], int n){
        
        // Your code here
      
     // return solve_using_arrays(arr,n);    ---> best solution
      
      
      return dp_solution_bottom_up(arr,n);    // -->givs TLE
    }
};



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends