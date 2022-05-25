#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define returnNo return void(puts("No"))
#define returnYes return void(puts("Yes"))

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p)
{
    return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
    os << '[';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << ']';
}

void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    debug_out(T...);
}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif
int dp[110][110][110];
void solve()
{
    int n, m, kk, q;
    cin >> n >> m >> kk >> q;

    vector<vector<int>> cost(n + 1, vector<int>(m + 1));
    map<int, int> c;

    for (int i = 1; i <= q; i++)
    {
        int u, v;
        cin >> u >> v;
        c[u] = v;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> cost[i][j];

    memset(dp, 0x3f, sizeof dp);
    int pre = 0;
    dp[1][0][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            for (int k = 0; k <= n; k++)
            {
                if (c[i] > 0)
                {
                    if (pre == c[i])
                        dp[i][c[i]][k] = min(dp[i][c[i]][k], dp[i - 1][pre][k] + cost[i][c[i]]);
                    else
                        dp[i][c[i]][k] = min(dp[i][c[i]][k], dp[i - 1][pre][k - 1] + cost[i][c[i]]);
                }
                else
                {
                    if (pre == j)
                        dp[i][j][k] = min(dp[i][j][k], dp[i - 1][pre][k] + cost[i][j]);
                    else
                        dp[i][j][k] = min(dp[i][j][k], dp[i - 1][pre][k - 1] + cost[i][j]);
                }
            }
        }
    }
    long long ans = 1e12;
    for (int i = 1; i <= m; i ++ )
    {
        ans = min(ans, dp[n][i][kk]);
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
}