#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define returnNo return void(puts("No"))
#define returnYes return void(puts("Yes"))
constexpr int N = 2e5 + 10;
vector<int>v[N];
int n, m, x, y, f[N], d[N];
bool vis[N];

inline void dfs(int x)
{
    for (auto &y : v[x])
    {
        d[y] = 1 + d[x];
        f[y] = x;
        dfs(y);
    }
}

void solve()
{
    cin >> n >> m;
    cin >> x >> y;
    vector<int>q(m + 1);
    for (int i = 1; i <= m; i ++ )
    {
        cin >> q[i];
    }
    for (int i = 0; i < n; i ++ )
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b), v[b].push_back(a);
    }
    d[x] = 1;
    dfs(x);
    memset(b, 0, sizeof b);
    int v1 = 0, v2 = 0;
    for (int i = 1; i <= m; i ++ ) 
    {
        v2 = max(v2, d[q[i]]);
        int tmp = q[i];
        for ()
    }
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