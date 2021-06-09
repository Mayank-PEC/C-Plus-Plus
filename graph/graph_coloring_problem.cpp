#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vec(x) vector<x>
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define umpii unordered_map<int,int>
#define mem(a,b) memset(a, b, sizeof a)
#define prec(n) fixed<<setprecision(n)
#define ff first
#define ss second
#define print(x) for(auto it:x) cout<<it<<" ";
#define fast_in_out ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
vector<int> adjlist[1000];
bitset<1000> vis,availability;
int color_of_vertex[1000];


// Following is the basic Greedy Algorithm to assign colors. 
// It doesn’t guarantee to use minimum colors, but it guarantees
//  an upper bound on the number of colors. The basic algorithm 
//  never uses more than d+1 colors where d is the maximum 
//  degree of a vertex in the given graph.


// finding the chromatic number and the 
// color given to a vertex
int main()
{
    fast_in_out;
   int t=1;
    cin>>t;
    while(t--)
{

         int n,m;
        cin>>n>>m;
         for(int i=0;i<1000;i++)
             adjlist[i].clear();
         vis.reset();
         availability.reset();   // value being set means that ,that color is taken
                           // by it's neighbours

        memset(color_of_vertex,-1,sizeof(color_of_vertex));
         while(m--)
         {
             int x,y;
             cin>>x>>y;
             adjlist[x].pb(y);
             adjlist[y].pb(x);
         }

        color_of_vertex[1]=0;
        int chroma_number=0;
      for(int i=1;i<=n;i++)
      {
          for(int child:adjlist[i])
          {
              if(color_of_vertex[child]!=-1)
              {
                  availability[color_of_vertex[child]]=1;
              }
          }

          int cr;

          for(cr=0;cr<n;cr++)
          {
              if(availability[cr]==0)
                  break;

          }

          color_of_vertex[i]=cr;

          chroma_number=max(chroma_number,cr+1);

          for(int child:adjlist[i])
          {
              if(color_of_vertex[child]!=-1)
                 availability[color_of_vertex[child]]=0;    //0--->means that the color is now available

          }
      }

      cout<<"Chromatic Number = "<<chroma_number<<"\n";
      for(int i=1;i<=n;i++)
         cout<<i<<" = "<<color_of_vertex[i]<<"\n";

}



}
// Making Schedule or Time Table: Suppose we want to 
// make am exam schedule for a university. We have
//  list different subjects and students enrolled in 
//  every subject. Many subjects would have common students
//   (of same batch, some backlog students, etc). How do 
//   we schedule the exam so that no two exams with a 
//   common student are scheduled at same time? How 
//   many minimum time slots are needed to schedule 
//   all exams? This problem can be represented as 
//   a graph where every vertex is a subject and an 
//   edge between two vertices mean there is a common 
//   student. So this is a graph coloring problem where
//    minimum number of time slots is equal to the chromatic number of the graph. 