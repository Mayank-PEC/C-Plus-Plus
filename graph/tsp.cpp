#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
/*int A[4][4]={
             {0,20,42,25},
             {20,0,30,34},
             {42,30,0,10},
             {25,34,10,0}
             };

int solve_TSP_bitmasking(int mask,int pos,int n)
{  

    if(mask==(1<<n)-1)
        return(A[pos][0]);

    int ans=INT_MAX,smallAns=0;
    for(int city=0;city<n;city++)
    {
        if(mask&(1<<city)==0)
        {
            smallAns=solve_TSP(mask|(1<<city),city,n);
            ans=min(smallAns,ans);
        }
    }

    return(ans);

}*/
int graph[100][100];
int n,m,start;
bool visited[100]={0};
ll dp[2][100];
bool AllVisited()    //checks if something remains unvisited in visited array...
{
    for(int i=1;i<=n;i++)
        if(visited[i]==0)
          return false;
    return true;
}


ll SolveTSP(int pos)            //recursive....
{
    if(AllVisited())                             //O(n)
        return graph[pos][start];

    ll ans=INT_MAX,smallAns;
    for(int i=1;i<=n;i++)
    {
       // cout<<i<<" ";
        if(!visited[i])
        {
            visited[i]=1;
            smallAns=graph[pos][i]+SolveTSP(i);
           // cout<<i<<"\n";
            ans=min(smallAns,ans);
           // cout<<ans<<"\n";
             visited[i]=0;
        }

    }

    //cout<<"\n";
    return ans;
}


/*ll SolveTSP_TopDown(int pos)
{
    if(AllVisited())
        return graph[pos][start];
    if(dp[pos]!=-1)
        return dp[pos];

        int ans=INT_MAX;
        int SmallAns;
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            visited[i]=1;
            int SmallAns=graph[pos][i]+SolveTSP_TopDown(i);
            ans=min(SmallAns,ans);
            visited[i]=0;
              //dp[i]=ans;
        }

    }
    return dp[pos]=ans;

}
*/

ll SolveTSP_BottomUp(int pos)
{
    ll dp[100][n+1];
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        dp[i][n]=graph[i][pos];
    }


    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
          dp[pos][i]=graph[pos][i];
    }

        int SmallAns;
        int ans;
   /* for(int i=1;i<n-1;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(!visited[j])
            {
                visited[j]=1;


            }
        }
    }*/
    for(int i=1;i<=n;i++)
    {
        SmallAns=0;
        ans=INT_MAX;
        if(!visited[i])
        {
            visited[i]=1;
           for(int j=1;j<=n;j++)
        {
            if(!visited[j])
            {
                visited[j]=1;
             SmallAns=graph[j][i];
             ans=min(SmallAns,ans);
            }
           visited[j]=0;
           dp[j][i]=ans;
        }
         visited[i]=0;

        }

        }
        ll FinalAns=INT_MAX;
        for(int i=1;i<=n;i++)
        {
            FinalAns=min(dp[i][2],FinalAns);
        }
        return FinalAns;
}
int main()
{

   // cout<<solve_TSP(1,0,4);
   for(int i=0;i<100;i++)
    for(int j=0;j<100;j++)
      graph[i][j]=INT_MAX;

   // for(int i=0;i<100;i++)
   //     dp[i]=-1;

   cout<<"Enter the number of vertex = ";
   cin>>n;
   cout<<"Enter the number of edges = ";
   cin>>m;
   cout<<"Enter the vertex with edge from u--->v and the weight :"<<"\n";
   int u,v,w;
   while(m--)
   {
       cin>>u>>v>>w;
       graph[u][v]=w;
   }
   cout<<"Enter the position or the vertex from where the salesperson will start = ";
   cin>>start;

   visited[start]=1;

   int ans=SolveTSP(start);
   //int ans=SolveTSP_TopDown(start);
  //int ans=SolveTSP_BottomUp(start);
   cout<<ans<<"\n";

  // for(int i=1;i<=n;i++)
   // cout<<dp[i]<<" ";

}



/***************************Below implementation is very clear ***********************************/



#include<iostream>
using namespace std;

int n=4;
int dist[10][10] = {
        {0,20,42,25},
        {20,0,30,34},
        {42,30,0,10},
        {25,34,10,0}
};
int VISITED_ALL = (1<<n) -1;

int dp[16][4];    // space ---> (n*2^n)


int  tsp(int mask,int pos){
	
	if(mask==VISITED_ALL){
		return dist[pos][0];
	}
	if(dp[mask][pos]!=-1){
	   return dp[mask][pos];
	}

	//Now from current node, we will try to go to every other node and take the min ans
	int ans = INT_MAX;

	//Visit all the unvisited cities and take the best route
	for(int city=0;city<n;city++){

		if((mask&(1<<city))==0){

			int newAns = dist[pos][city] + tsp( mask|(1<<city), city);
			ans = min(ans, newAns);
		}

	}
	
	return dp[mask][pos] = ans;
} 

int main(){
    /* init the dp array */
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            dp[i][j] = -1;
        }
    }
	cout<<"Travelling Saleman Distance is "<<tsp(1,0);

return 0;
}


/***************************************************************************************/