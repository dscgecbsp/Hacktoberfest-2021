#include <bits/stdc++.h>
using namespace std;

//  using memoization
vector<vector<int>> t(5, vector<int>(102, -1));
int unbounded_knapsack(int val[], int wt[], int n, int W)
{
    if (n == 0 || W == 0)
        return 0;

    if (t[n][W] != -1)
        return t[n][W];

    if (wt[n - 1] > W)
        return t[n][W] = unbounded_knapsack(val, wt, n - 1, W);

    else if (wt[n - 1] <= W)
        return t[n][W] = max(unbounded_knapsack(val, wt, n - 1, W), val[n - 1] + unbounded_knapsack(val, wt, n, W - wt[n - 1]));
}

//  using down top approach

int unbounded_knapsack_dp(int val[], int wt[], int n, int W)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < W + 1; j++)
        {

            if (i == 0 || j == 0)
                dp[i][j] = 0;

            else if (wt[i - 1] > j)
                dp[i][j] = dp[i - 1][j];

            else
                dp[i][j] = max(dp[i - 1][j], val[i - 1] + dp[i][j - wt[i - 1]]);
        }
    }
    return dp[n][W];
}
int main()
{
    int val[] = {10, 30, 20};
    int wt[] = {5, 10, 15};
    int W = 100;
    int n = sizeof(val) / sizeof(val[0]);
    cout << unbounded_knapsack_dp(val, wt, n, W);
    return 0;
}