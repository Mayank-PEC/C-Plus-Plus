#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    
   /*  int dx[4]={-1,0,1,0};     //'L'  'R'  'D'  'U'
        int dy[4]={0,1,0,-1};*/
      
      
  /*  bool isValid(int r,int c,vector<vector<int>> m,int n)
    {
        if(r>=n || r<0 || c>=n || c<0)
          return false;
          
         if(m[r][c]==0)
           return false;
           
          return true;
    }*/
    
    
      bool vis[10][10];
      vector<string> vec;
      
    
   void  dfs(vector<vector<int>> &m ,int n,int s,int e,string str)
    {
         
         if(s<0 || s>=n || e<0 || e>=n)
           return ;
           
         if(m[s][e]==0 || vis[s][e]==1)
          return ;
          
          if(s==n-1 && e==n-1)
           {
               vec.push_back(str);
               return ;
           }
         
           
         vis[s][e]=1;
         
         
         dfs(m,n,s-1,e,str+'U');
         dfs(m,n,s,e+1,str+'R');
         dfs(m,n,s+1,e,str+'D');
         dfs(m,n,s,e-1,str+'L');
         
         vis[s][e]=0;
         
        
         
         
        
    }
    
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
       
           vec.clear();
       if(m[0][0]==0 || m[n-1][n-1]==0)
         return vec;
         
       memset(vis,0,sizeof(vis));
       dfs(m,n,0,0,"");
        
      
        sort(vec.begin(),vec.end());
           
           
         //  cout<<vec.size()<<"\n";
         return vec;
        
        
    }
};
/*
 Common Syntax Of Any Backtraking code :-

bool recur(){
    if(){} else(){} ..........Terminating Conditions
    
     if( we achieved goal ){
         return true;
       }
     
      for( Check every directions ){
          old_var = new_var;          .........change single point 
          if( recur() ){ return true; }  .............check if we are right about this point.
          new_var = old_var;        ..............no this point failed reverse changes and loop continue.
      }
      
     return false;    ...........if we cant find any direction to go return false;     
}


*/





    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends