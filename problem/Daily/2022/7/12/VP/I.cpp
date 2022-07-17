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
constexpr int N = 2e5 + 10, MOD = 1e9 + 7;

vector<int> e[N];
int father[N];
int sz[N];
int n, m;
map<int, int> mp;

void dfs(int u, int fa, int root)
{
    mp[u] = 1;
    father[u] = root;
    if (e[u].empty())
    {
        sz[u] = 1;
    }
    for (auto &j : e[u])
    {
        if (j == fa)
            continue;
        if (!mp.count(j))
        {
            mp[j] = 1;
            dfs(j, u, root);
        }
        sz[u] = (sz[u] + sz[j]) % MOD;

        debug(u, j, sz[u], sz[j]);
    }
}

void solve()
{
    cin >> n >> m;
    vector<int> v(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        for (int j = 1; j <= x; j++)
        {
            int y;
            cin >> y;
            e[i].push_back(y);
        }
    }
    dfs(1, 1 ,1);
    int after = 0;
    int before = sz[1];
    for (int i = m + 1; i <= n; i++)
    {
        if (father[i] == 1)
        {
            //cout << i << endl;
            after ++;
        }
    }
    cout << before << ' ' << after << endl;
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