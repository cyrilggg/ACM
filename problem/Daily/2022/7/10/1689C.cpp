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
constexpr int N = 3e5 + 10;

vector<int> edges[N];
int sizes[N], dp[N];

void dfs(int u, int fa)
{
    for (int i = 0; i < edges[u].size(); i++)
    {
        int j = edges[u][i];
        if (j == fa)
            continue;
        dfs(j, u);
        sizes[u] += sizes[j];
    }
    for (int i = 0; i < edges[u].size(); i++)
    {
        int j = edges[u][i];
        if (j == fa)
            continue;
        dp[u] = max(dp[u], dp[j] + sizes[u] - sizes[j] - 2);
    }
    if((fa == -1 && edges[u].size() == 1) || (fa != -1 && edges[u].size() == 2))
        dp[u] = max(dp[u], sizes[u] - 2);
}

int count(int u, int fa)
{
    int cnt = 0;
    vector<pair<int,int>>v;
    for (int i = 0; i < edges[u].size(); i ++ )
    {
        int j = edges[u][i];
        if (j == fa) continue;
        v.push_back({j, sizes[j]});
    }
    //debug(v);
    if (v.size() == 1)
    {
        cnt += v[0].second - 1;
    }
    else if (v.size() == 2)
    {
        int v1 = count(v[1].first, u), v0 = count(v[0].first, u);
        //debug(v1, v0, v[1].first , v[0].first, v[1].second , v[0].second);
        if (v[0].second > v[1].second)
        {
            cnt += v[0].second - 1;
            cnt += count(v[1].first, u);
        }
        else if (v[0].second < v[1].second)
        {
            cnt += v[1].second - 1;
            cnt += count(v[0].first, u);
        }
        else
        {
            if (v0 < v1)
            {
                cnt += v[0].second - 1;
                cnt += v1;
            }
            else
            {
                cnt += v[1].second - 1;
                cnt += v0;
            }
        }
    }
    //debug(u, cnt);
    return cnt;
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        sizes[i] = 1;
        dp[i] = 0;
        edges[i].clear();
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(1, -1);
    cout << dp[1] << endl;
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