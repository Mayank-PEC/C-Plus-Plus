#include<bits/stdc++.h>
using namespace std;

int done,ans=0;
int board[20][20]={0};
int get_position(int x)
{
    int ans=0;
    while(x)
    {
        x=x>>1;
        ans++;
    }
    return ans-1;
}
void solve(int rowmask,int ld,int rd,int row)
{
      if(rowmask==done) {
           ans++ ;

           for(int i=0;i<row;i++)
           {
               for(int j=0;j<row;j++)
                 {
                     cout<<board[i][j];
                 }cout<<"\n";
           }cout<<"\n";
           return ;

           }
      
     int  safe = done &(~(rowmask|ld|rd));       // done and with "done" to remove the extra bits which
                                                 // which have be moved out of place   

     while(safe)
     {
        int  p = safe&(-safe);       // p gives us a number with last set bit 
        int col = get_position(p);    // here log can also be taken ....instead of the function as
                                      // p will always contain all zeros except at one postion where
         board[row][col]=1;            // it will have a 1 as the set bit
         safe = safe - p;
                                              
        
         solve(rowmask|p , (ld|p)<<1 , (rd|p)>>1 ,row+1);

         board[row][col]=0;
     }

}
int main()
{
    int n;
    cout<<"Enter value for n = ";
    cin>>n;
     
    done = (1<<n)-1;
    solve(0,0,0,0);
    cout<<ans<<"\n";

}