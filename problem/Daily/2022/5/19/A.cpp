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
constexpr int N = 1010;
int fa[N];
map<int, vector<pair<int, int>>> mp;
int Find(int x)
{
    return fa[x] == x ? fa[x] : fa[x] = Find(fa[x]);
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> v(n + 1);
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 1; i <= n; i++)
        cin >> v[i].first;
    for (int i = 1; i <= n; i++)
        cin >> v[i].second;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        fa[Find(a)] = Find(b);
    }
    for (int i = 1; i <= n; i++)
        mp[Find(i)].push_back(v[i]);

    for (int i = 1; i <= n; i++)
    {
        int a = 0, b = 0;
        for (int j = 0; j < mp[i].size(); j++)
            a += mp[i][j].first, b += mp[i][j].second;
        mp[i].push_back({a, b});
    }
    vector<vector<int>> dp(n + 1, vector<int>(k + 10));
    for (int i = 1; i <= n; i++)
    {
        for (int j = k; j >= 0; j--)
        {
            for (int s = 0; s < mp[i].size(); s++)
            {
                dp[i][j] = max(dp[i][j], dp[max(i - 1, 0ll)][j]);
                if (j >= mp[i][s].first)
                {
                    dp[i][j] = max(dp[i][j], dp[max(i - 1, 0ll)][j - mp[i][s].first] + mp[i][s].second);
                    debug(i, j, dp[i][j]);
                }
            }
        }
    }
    cout << dp[n][k] << endl;
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