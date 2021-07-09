// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


// User function Template for C++

class Solution{
public:
    int nCr(int n, int r)
    {
        // code here
        
        if(r==0)
         return 1;
         
        if(n<r)
         return 0;
        
        long long int dp[r+1];
        int mod=1000000007;
        memset(dp,0,sizeof(dp));
        
     /*   for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<r+1;j++)
            {
             
                if(j==0)
                 dp[i][j]=1;
                 
                if(i==j)
                 dp[i][j]=1;
                 
        
            }
        }*/
        
        r=min(r,n-r);
        dp[0]=1;    //refer pascal's triangle
        
        
        for(int i=1;i<=n;i++)
        {
            for(int j=min(i,r);j>=1;j--)
            {
                dp[j]=(dp[j]+dp[j-1])%mod;
            }
        }
        
     /*   for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<r+1)
        }*/
        
       return dp[r];
    }


};


/*
nCr = number of ways to choose r elements from a 
set of n elements
suppose we know the number of ways to 
choose r=(0,1,2,...,n-1) elements from
a set for n-1 elements
(i.e. we know (n-1)C0, (n-1)C1, ... , (n-1)C(n-1)) 
we can caluclate nCr using following fact
say we have a bag containing n-1 distinct 
balls and we know the number of ways to choose
r balls from the bag and we also know the number
of ways to choose r-1 balls from the bag.

now suppose we add another ball to the
bag and now we want to choose r balls from n balls.
now we can either completely ignore the 
newly added ball and choose r balls from 
the earlier existing n-1 balls 
(this can be done in (n-1)C(r) ways)
or we choose to pick newly added ball 
and choose rest of the r-1 balls from
the eariler n-1 balls[this can be done in (n-1)C(r-1) ways]
since we can either ignore or choose the
newly added ball to select r balls from 
the bag then we can say that choosing r 
balls from n balls is (n-1)C(r-1)+(n-1)C(r). 
and this number equals nCr


*/










// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends