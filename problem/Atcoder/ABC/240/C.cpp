#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1010;
int dp[110][10010];
void solve()
{
    dp[0][0] = 1;
    int n, x;
    vector<pair<int,int>>v(n + 1);
    cin >> n >> x;
    for (int i = 1; i <= n; i ++ )
    {
        cin >> v[i].first >> v[i].second;
    }
    for (int i = 1; i <= n; i ++ )
    {
        for (int j = x; j >= 0; j -- )
        {
            if (j >= v[i].first) dp[i][j] |= dp[i - 1][j - v[i].first];
            if (j >= v[i].second) dp[i][j] |= dp[i - 1][j - v[i].second];
        }
    }
    if(dp[n][x])puts("Yes");
    else puts("No");
}

signed main()
{
   int t = 1;
   //cin >> t;
   while (t -- )solve();
}