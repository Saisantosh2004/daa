#include <iostream>
#include <vector>
using namespace std;

#define INT_MIN -10000000

int max(int a, int b) { return a > b ? a : b; }

int binaryKnapsack(int C, int wt[], int val[], int n) {
  vector<vector<int>> dp(n, vector<int>(C + 1, 0));

  for (int i = wt[0]; i <= C; i++) {
    dp[0][i] = val[0];
  }

  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= C; j++) {

      int nT = 0 + dp[i - 1][j];
      int T = INT_MIN;
      if (wt[i] <= j) {
        T = val[i] + dp[i - 1][j - wt[i]];
      }

      dp[i][j] = max(nT, T);
    }
  }

  return dp[n - 1][C];
}

int main() {
  int profit[] = {60, 100, 120};
  int weight[] = {10, 20, 30};
  int W = 50;
  int n = sizeof(profit) / sizeof(profit[0]);

  cout << binaryKnapsack(50, weight, profit, n);
}
