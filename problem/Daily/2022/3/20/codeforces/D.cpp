#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10, M = 2 * N;
const int mod = 998244353;
int h[N], e[M], ne[M], idx;
bool st[N];
pair<int,int>w[M], is[N];
int n;

void add(int a, int b, pair<int,int>x)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = x, h[a] = idx ++;
}

void dfs(int u)
{
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        cout << j <<' '<< u << endl;
        if (st[j]) continue;
        is[j].second = w[i].first * is[u].first;
        is[j].first = w[i].second * is[u].second;
        st[j] = 1;
        dfs(j);
    }
}

void solve()
{
    memset(h, -1, sizeof h);
    cin >> n;
    for (int i = 1; i < n; i ++ )
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        add(a, b, {c, d});
        add(b, a, {d, c});
    }
    is[1] = {1, 1};
    st[1] = 1;
    dfs(1);
    cout << "done" <<endl;
    int lcm = 1;
    for (int i = 1; i <= n; i ++ )
    {
        lcm = is[i].second * lcm / (__gcd(lcm, is[i].second));
    }
    int ans = 0;
    for (int i = 1; i <= n; i ++ )
    {
        ans = (ans + is[i].first * lcm) % mod; 
    }
    cout << ans << endl;
}

signed main()
{
   int t = 1;
   cin >> t;
   while (t -- )solve();
}