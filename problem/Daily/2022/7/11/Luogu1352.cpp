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


vector<int> edges[N], v;
vector<vector<int>> dp;

void dfs(int u)
{
    dp[u][1] = v[u];
    for (int i = 0; i < edges[u].size(); i ++ )
    {
        int j = edges[u][i];
        dfs(j);
        dp[u][0] += max(dp[j][0], dp[j][1]);
        dp[u][1] += dp[j][0];
    }
}

void solve()
{
    int n;
    cin >> n;
    dp.resize((n + 1), vector<int>(2));
    v.resize(n + 1);
    map<int,int>mp;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        mp[a] = 1;
        edges[b].push_back(a);
    }
    for (int i = 1; i <= n; i ++ )
    {
        if (!mp.count(i))
        {
            dfs(i);
            cout << max(dp[i][0], dp[i][1]) << endl;
            return;
        }
    }

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