#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 1e5 + 10, M = 2 * N;
int h[N], ne[M], e[M], idx;
int d[N], ans[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int u,int fa, int flag)
{
    ans[u] = flag * d[u];
    for (int  i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (j == fa) continue;
        dfs(j, u, -flag);
    }
}

void solve()
{
    memset(d, 0, sizeof d);
    memset(h, -1, sizeof h);
    idx = 0;
    int n;
    cin >> n;
    for (int i = 1; i < n; i ++ )
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
        d[a] ++, d[b] ++;
    }
    dfs(1, 1, 1);
    for (int i = 1; i <= n; i ++ )
        cout << ans[i] << " \n"[i == n];
    
}

signed main()
{
   int t = 1;
   cin >> t;
   while (t -- )solve();
}