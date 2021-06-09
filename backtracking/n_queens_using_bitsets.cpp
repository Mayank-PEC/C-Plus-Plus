#include<bits/stdc++.h>
using namespace std;
bitset <20>col,diagl,diagr;
bool NQUEENS_Bitset(int board[][20],int row,int n)
{
    static int count=1;
     if(row==n)
    {
        cout<<count<<")";
     for(int i=0;i<n;i++)
     {
         for(int j=0;j<n;j++)
        {
           if(board[i][j])
           {
               cout<<" Q ";
           }
           else
           {
               cout<<" _ ";
           }
        }cout<<endl;
     }cout<<endl;
     count++;
     return(false);
    }

    for(int column=0;column<n;column++)
    {
        if(!(col[column] || diagl[row-column+n-1] || diagr[row+column]))
        {
            board[row][column]=1;
            col[column]=1;
            diagl[row-column+n-1]=1;
            diagr[row+column]=1;
            if(NQUEENS_Bitset(board,row+1,n))
            {
                return(true);
            }
             col[column]=0;
             board[row][column]=0;
            diagl[row-column+n-1]=0;
            diagr[row+column]=0;

        }
    }
  return(false);
}
int main()
{
    int board[20][20]={0},n;
    cin>>n;
    NQUEENS_Bitset(board,0,n);
}
