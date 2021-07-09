#include <iostream>
#include <climits>
using namespace std;

// Function to find the Minimum number of coins required to get Sum S
int findMinCoins_best_solution(int arr[], int n, int N)
{
	// dp[i] = no of coins required to get a total of i
	int dp[N + 1];

	// 0 coins are needed for 0 sum

	dp[0] = 0;

	for (int i = 1; i <= N; i++)
	{
		// initialize minimum number of coins needed to infinity
		dp[i] = INT_MAX;                       
		int res = INT_MAX;

		// do for each coin
		for (int c = 0; c < n; c++)
		{
			if (i - arr[c] >= 0) // check if coins doesn't become negative by including it
				res = dp[i - arr[c]];

			// if total can be reached by including current coin c,
			// update minimum number of coins needed dp[i]
			if (res != INT_MAX)
				dp[i] = min(dp[i], res + 1);
		}
	}

	// The Minimum No of Coins Required for N = dp[N]
	return dp[N];
}


 long long int count_my_solution( int S[], int m, int n )
    {
       
        //code here.
        long long int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<m+1;i++)
            dp[i][0]=1;
        
        
        
       /*  for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
              {
                  cout<<dp[i][j]<<" ";
              }cout<<"\n";
        }*/
        
        for(int i=1;i<=m;i++)      //set iteration
        {
            for(int j=0;j<=n;j++)   //amount...
            {
                if(j>=S[i-1])
                 dp[i][j]= dp[i][j-S[i-1]] + dp[i-1][j];
                else
                dp[i][j]=dp[i-1][j];
            }
        }
     /*   for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
              {
                  cout<<dp[i][j]<<" ";
              }cout<<"\n";
        }*/
        return dp[m][n];
       
        
    }

	int Solution_top_down(int amt, int *deno, int n, int *dp) {
    // base case
    if (amt == 0) {
        return dp[amt] = 0;
    }
    if (dp[amt] != -1) {
        return dp[amt];
    }
 
    // recursive case
    int ans = INT_MAX;
    for (int i = 0 ; i < n ; i++) {
        if (amt >= deno[i]) {
            int sa = Solution_top_down(amt - deno[i], deno, n, dp);
            if (sa != INT_MAX) {
                ans = min(sa + 1, ans);
            }
        }
    }
 
    return dp[amt] = ans;
}


int Bottom_up_solution( int S[], int m, int n )         
{         
 // table[i] will be storing the number of solutions for         
 // value i. We need n+1 rows as the table is constructed         
 // in bottom up manner using the base case (n = 0)         
 int table[n+1];         
 // Initialize all table values as 0         
 memset(table, 0, sizeof(table));         
 // Base case (If given value is 0)         
 table[0] = 1;         
 // Pick all coins one by one and update the table[] values         
 // after the index greater than or equal to the value of the         
 // picked coin         
 for(int i=0; i<m; i++)         
 for(int j=S[i]; j<=n; j++)         
 table[j] += table[j-S[i]];         
 return table[n];    
 
      
}         



int main()
{
	// No of Coins We Have
	int arr[] = {1, 2, 3, 4};
	int n = sizeof(arr) / sizeof(arr[0]);

	// Total Change Required
	int N = 15;

	cout << "Minimum Number of Coins Required " << findMinCoins_best_solution(arr, n, N) << "\n";

	return 0;
}