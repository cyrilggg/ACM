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
vector<int> sz;
int n, m;

void dfs(int u, int fa)
{
    sz[u] = 1;
    dp[u][0] = 0;
    dp[u][1] = 0;
    for (auto &v : e[u])
    {
        int j = v.first;
        if (j == fa)
            continue;
        dfs(j, u);
        sz[u] += sz[j];
        for (int i = min(m, sz[u]); i >= 0; --i)
        {
            if (dp[u][i] != -1)
                dp[u][i] += dp[j][0] + sz[j] * (n - m - sz[j]) * v.second;
            for (int k = min(i, sz[j]); k; --k)
            {
                if (dp[u][i - k] == -1)
                    continue;
                int val = (k * (m - k) + (sz[j] - k) * (n - m - sz[j] + k)) * v.second;
                dp[u][i] = max(dp[u][i], dp[u][i - k] + dp[j][k] + val);
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    sz.resize(n + 1);
    dp.resize(n + 1, vector<int>(m + 1, -1));
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    dfs(1, 1);
    cout << dp[1][m] << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int _ = 1;
    //cin >> _;
    while (_--)
        solve();
}