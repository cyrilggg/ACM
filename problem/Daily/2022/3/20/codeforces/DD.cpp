#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, M = 2 * N, mod = 998244353;
int h[N], e[M], ne[M], idx, ans;
pair<int,int>w[M];
vector<map<int,int>>mp(N);
int cnt[N], maxnum[N];

void add(int a, int b, pair<int,int>c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}

int qmi(int a, int k)  // Çóa^k mod p
{
    int res = 1;
    while (k)
    {
        if (k & 1) res = res * a;
        a = a * a;
        k >>= 1;
    }
    return res;
}

void dfs1(int u, int fa)
{
    for(int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if(j == fa) continue;
        for(auto [x, y] : mp[w[i].first])
            cnt[x] -= y;
        for(auto [x, y] : mp[w[i].second])
        {
            cnt[x] += y;
            maxnum[x] = max(maxnum[x], cnt[x]);
        }
        dfs1(j, u);
        for(auto [x, y] : mp[w[i].first]) cnt[x] += y;
        for(auto [x, y] : mp[w[i].second]) cnt[x] -= y;
    }
}
void dfs2(int u, int fa, int cur)
{
    ans = (ans + cur) % mod;
    for(int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if(j == fa) continue;
        dfs2(j, u, cur * w[i].second / w[i].first);
    }
};


void solve()
{
    ans = 0;
    memset(cnt, 0, sizeof cnt);
    memset(h, -1, sizeof h);
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i ++ )  maxnum[i] = 1;

    for (int i = 1; i < n; i ++ )
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        add(a, b, {c, d});
        add(b, a, {d, c});
    }
    dfs1(1, 1);

    int tot = 1;
    for (int i = 1; i <= n; i ++ ) tot *= qmi(i, maxnum[i]);
    dfs2(1, 1, tot);
    cout << ans << endl;
        
}
int main()
{
    for (int i = 2; i < 200010; i ++ )
    {
        int t = i;
        for(int j = 2; j <= t / j ; j ++ )
        {
            while(t % j == 0) t /= j, mp[i][j] ++ ;
        }
        if (t != 1) mp[i][t] ++;
    }
    int t;
    cin >> t;
    while (t -- ) solve();
    return 0;
}