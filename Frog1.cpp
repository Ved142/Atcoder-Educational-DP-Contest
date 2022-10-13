#include <bits/stdc++.h>

using namespace std;

// Recursive Approach
/*
int min_cost(int ind, vector<int> &arr, vector<int> &dp)
{
    if (ind <= 0)
    {
        return 0;
    }

    if (dp[ind] != -1)
    {
        return dp[ind];
    }

    int onestep = INT_MAX, twostep = INT_MAX;
    if ((ind - 1) >= 0)
    {
        onestep = abs(arr[ind] - arr[ind - 1]) + min_cost(ind - 1, arr, dp);
    }
    if ((ind - 2) >= 0)
    {

        twostep = abs(arr[ind] - arr[ind - 2]) + min_cost(ind - 2, arr, dp);
    }

    return dp[ind] = min(onestep, twostep);
 }
 */

int main()
{
    int N;
    cin >> N;
    vector<int> arr;
    for (int i = 0; i < N; i++)
    {
        int inp;
        cin >> inp;
        arr.push_back(inp);
    }
    vector<int> dp(N + 1, -1);
    for (int i = N; i >= 1; i--)
    {
        if (i == N)
        {
            dp[i] = 0;
        }
        else if (i == N - 1)
        {
            dp[i] = abs(arr[N - 1] - arr[N - 2]);
        }
        else if (i == N - 2)
        {
            dp[i] = abs(arr[N - 1] - arr[N - 3]);
        }
        else
        {
            dp[i] = min(abs(arr[i] - arr[i - 1]) + dp[i + 1], abs(arr[i - 1] - arr[i + 1]) + dp[i + 2]);
        }
    }

    cout << dp[1] << "\n";

    return 0;
}