#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAX_N = 21;
int cost[MAX_N][MAX_N]={{0,10,15,20},{10,0,35,25},{15,35,0,30},{20,25,30,0}};
int dp[MAX_N][(1 << MAX_N)];

int solve(int u, int mask, int& n)
{
    if(mask == (1 << n) - 1) 
        return cost[u][0];
 
    if(dp[u][mask] != -1)
        return dp[u][mask];
 
    int answer = INT_MAX;
    for(int v = 0; v < n; v++)
    {
        if(!(mask & (1 << v)))
            answer = min(answer, cost[u][v] + solve(v, (mask | (1 << v)), n));
    }
 
    return dp[u][mask] = answer;
}

int main() {

   memset(dp, -1, sizeof dp);
   int n=4;
   cout << solve(0, 1, n) << '\n';
   return 0;
}
