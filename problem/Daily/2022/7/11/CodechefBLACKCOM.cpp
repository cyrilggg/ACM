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

//#define int long long
#define endl '\n'
constexpr int N = 2e5 + 10;

vector<int> e[N];
vector<vector<vector<int>>> dp;
vector<int> sz, v;
map<int, int> F, G;

int n, m;

void dfs(int u, int fa)
{
    sz[u] = 1;
    if (v[u])
    {
        dp[u][1][0] = dp[u][1][1] = 1;
    }
    else
    {
        dp[u][1][0] = dp[u][1][1] = 0;
    }
    for (auto &j : e[u])
    {
        if (j == fa)
            continue;
        dfs(j, u);
        for (int i = sz[u]; i >= 1; i--)
        {
            for (int k = 1; k <= sz[j]; k++)
            {
                dp[u][i + k][0] = min(dp[u][i + k][0], dp[u][i][0] + dp[j][k][0]);
                dp[u][i + k][1] = max(dp[u][i + k][1], dp[u][i][1] + dp[j][k][1]);
                debug(dp[u][i + k][0], dp[u][i + k][1], i, k, j, u);
            }
        }
        sz[u] += sz[j];
    }

    for (int i = 1; i <= sz[u]; i++)
    {
        F[i] = min(F[i], dp[u][i][0]);
        G[i] = max(G[i], dp[u][i][1]);
    }
}

void solve()
{
    scanf("%d%d", &n, &m);
    sz.resize(n + 1);
    v.resize(n + 1);
    dp.resize(n + 1, vector<vector<int>>(n + 1, vector<int>(2)));
    for (int i = 1; i <= n; i++)
        e[i].clear();
    for (int i = 1; i <= n; i++)
        F[i] = 1e12, G[i] = 0;
    for (int i = 1; i < n; i++)
    {
        int u, vv;
        scanf("%d%d", &u, &vv);
        e[u].push_back(vv);
        e[vv].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &v[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j][0] = 1e12;
            dp[i][j][1] = 0;
        }
    }

    dfs(1, 1);

    while (m--)
    {
        int s, b;
        scanf("%d%d", &s, &b);
        if (F[s] <= b && G[s] >= b)
            printf("Yes\n");    
        else
            printf("No\n");   
    }
}

signed main()
{
    int _ = 1;
    scanf("%d", &_);
    while (_--)
        solve();
}