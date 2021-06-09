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


#define MAXSIEVE 100000000 // All prime numbers up to this
#define MAXSIEVEHALF (MAXSIEVE/2)
#define MAXSQRT 5000 // sqrt(MAXSIEVE)/2
char a[MAXSIEVE/16+2];
#define isprime(n) (a[(n)>>4]&(1<<(((n)>>1)&7))) // Works when n is odd


void seive()
{
    int i,j;
  memset(a,255,sizeof(a));
  a[0]=0xFE; // 254

for(i=1;i<MAXSQRT;i++)
  if (a[i>>3]&(1<<(i&7)))
    for(j=i+i+i+1;j<MAXSIEVEHALF;j+=i+i+1)
         a[j>>3]&=~(1<<(j&7));
}


