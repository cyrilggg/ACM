#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
//#define endl '\n'
#define returnNo return void(puts("No"))
#define returnYes return void(puts("Yes"))

const int N = 150000 + 10;
vector<int> vv[N];
int n;
int d[N];
int ans[N];
void work(vector<int> &v, int u)
{
    int cnt = 0;
    // sort(v.begin(), v.end());
    for (int i = v.size() - 1, j = v.size() - 2; i >= 0 && j >= 0;)
    {
        while (i >= 0 && j >= 0 && v[i] > v[j])
        {
            i--;
            j--;
            cnt++;
        }
        while (i >= 0 && j >= 0 && v[i] == v[j])
        {
            j--;
        }
    }
    ans[u] = max(ans[u], cnt);
}
vector<int> dfs(int u, int fa)
{
    vector<int> res;
    if (vv[u].size())
    {
        for (int i = 0; i < vv[u].size(); i++)
        {
            if (vv[u][i] == fa)
                continue;
            vector<int> tmp = dfs(vv[u][i], u);
            auto bak = res;
            work(res, vv[u][i]);
            merge(tmp.begin(), tmp.end(), bak.begin(), bak.end(), res.begin());
        }
        res.push_back(d[u]);
    }
    else
        res.push_back(d[u]);

    return res;
}

void solve()
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &d[i]);
    }
    for (int i = 1; i < n; i++)
    {
        int a, b;
        scanf("%lld%lld", &a, &b);
        vv[a].push_back(b);
        vv[b].push_back(a);
    }
    dfs(1, 1);
    for (int i = 1; i <= n; i++)
        printf("%lld ", ans[i]);
}

signed main()
{
    int _ = 1;
    // cin >> _;
    while (_--)
        solve();
}