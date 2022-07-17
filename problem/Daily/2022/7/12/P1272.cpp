#include <bits/stdc++.h>
using namespace std;

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

#define int long long
#define endl '\n'
constexpr int N = 2e5 + 10;

vector<pair<int, int>> e[N];
vector<vector<int>> dp;
vector<int> sz, v;
int n, m;
map<int, vector<int>> mp;

void dfs(int u, int fa)
{
    if (u > n - m)
    {
        dp[u][1] = v[u];
        sz[u] = 1;
    }
    for (auto &vv : e[u])
    {
        int j = vv.first, w = vv.second;
        if (j == fa) continue;
        dfs(j, u);
        sz[u] += sz[j];
        for (int i = sz[u]; i >= 1; i -- )
        {
            for (int k = 1; k <= i; k ++ )
            {
                dp[u][i] = max(dp[u][i], dp[u][i - k] + dp[j][k] - w);
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    sz.resize(n + 1);
    v.resize(n + 1);
    dp.resize(n + 1, vector<int>(n + 1, -1e12));
    for (int i = 1; i <= n; i++)
        e[i].clear();
    for (int i = 1; i <= n - m; i++)
    {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            int a, b;
            cin >> a >> b;
            e[i].push_back({a, b});
        }
    }
    for (int i = n - m + 1; i <= n; i++)
        cin >> v[i];
    for (int i = 1; i <= n; i++)
        dp[i][0] = 0;
    
        dfs(1, 1);
    int cnt = 0;
    for (int i = m; i >= 1; i--)
    {
        if (dp[1][i] >= 0)
        {
            cnt = i;
            break;
        }
    }
    cout << cnt << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--)
        solve();
}