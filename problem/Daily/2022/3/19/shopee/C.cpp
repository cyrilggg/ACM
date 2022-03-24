#include <bits/stdc++.h>
using namespace std;

int idx;
int n, m, d;
int dp[310][150010];

struct Node
{
    int  a, b, t;
    bool operator<(const Node& x) const
    {
        return t < x.t;
    }
}fire[310];
int ans = -0x3f3f3f3f;
int main()
{
    memset(dp, -0x3f, sizeof dp);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> d;
    for (int i = 1; i <= m; i ++ )
    {
        int a, b, t;
        cin >> fire[i].a >> fire[i].b >> fire[i]. t;
    }
    sort(fire + 1, fire + 1 + m);

    for (int i = 1; i <= m; i ++ )
        for (int j = 1; j <= n; j ++ )
        {
            int diff = fire[i].t - fire[i - 1].t;
            for (int k = diff; k >= -diff; k -- )
            {
                if (j + k * d >= 0 && j + k * d <= n)
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j + k * d] + fire[i].b - abs(fire[i].a - j));
                    ans = max(ans, dp[i][j]);
                }
            }
        }
    cout << ans << '\n';
    return 0;
}