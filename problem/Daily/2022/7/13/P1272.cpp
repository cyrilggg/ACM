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
constexpr int N = 200;
vector<int> e[N];
vector<vector<int>> dp;
int n, p;

void dfs(int u, int fa)
{
    dp[u][1] = e[u].size(); // 保留一个点时其余的边全部拆掉
    for (auto &j : e[u])
    {
        if (j == fa) continue;
        dfs(j, u);

        for (int i = p; i > 0; i -- )
        {
            for (int k = 1; k < i; k ++ )
            {
                dp[u][i] = min(dp[u][i], dp[u][i - k] + dp[j][k] - 2);
            }
        }
    }
}

void solve()
{
    cin >> n >> p;
    dp.resize(n + 1, vector<int>(n + 1, 1e12));
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    dfs(1, 1);
    int ans = 1e12;
    for (int i = 1; i <= n; i++)
    {
        ans = min(ans, dp[i][p]);
    }
    cout << ans << endl;
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
