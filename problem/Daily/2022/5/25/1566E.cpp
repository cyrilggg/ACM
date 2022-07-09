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

vector<int> g[N];
int bud[N];
int n, res = 1, x;

void dfs(int u, int fa)
{
    bud[u] = 0;
    for (auto &v : g[u])
    {
        if (v == fa)
            continue;
        dfs(v, u);
        bud[u] |= !bud[v];
        if (u == 1 && !bud[v])
            res = 0;
    }
    x += (u != 1 && bud[u]);
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ )g[i].clear();
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    x = 0, res = 1;
    dfs(1, 0);
    cout << n - 1 - x - x + res << endl;
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