#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 200010;
vector<pair<int,int>>v;
vector<int>g[N];
int siz[N], dep[N];
priority_queue<int>q;

void dfs(int x, int fa)
{
    dep[x] = dep[fa] + 1;
    siz[x] = 1;
    for (auto e : g[x])
    {
        if (e == fa) continue;
        dfs(e, x);
        siz[x] += siz[e];
    }
    q.push(dep[x] - siz[x]);
}

void solve()
{
   int n, k;
   cin >> n >> k;
   for (int i = 1; i < n; i ++ )
   {
       int u, v;
       cin >> u >> v;
       g[u].push_back(v);
       g[v].push_back(u);
   }
   dfs(1, 0);
   int ans = 0;
   for (int i = 0; i < k; i ++ )
   {
       ans += q.top();
       q.pop();
   }
   cout << ans << endl;
}

signed main()
{
   int _ = 1;
   //cin >> _;
   while ( _-- )solve();
}