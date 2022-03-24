#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 10;

int l, r, f[N];
bool vis[N];

ll gcd(ll a, ll b)
{
    return !b ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

struct node
{
    int l, r;
    ll w;
    friend inline bool operator<(const node &a, const node &b)
    {
        return a.w < b.w;
    }
};

vector<node> edge;

void Kruskal()
{
    sort(edge.begin(), edge.end());
    int cnt = 0;
    ll ans = 0;
    for (auto e : edge)
    {
        int x = e.l, y = e.r;
        ll w = e.w;
        if (find(x) != find(y))
        {
            // printf("%d %d %lld\n",x,y,w);
            f[max(find(x), find(y))] = min(find(x), find(y));
            ans += w;
        }
    }
    printf("%lld\n", ans);
}

signed main()
{
    cin >> l >> r;
    ll ans = 0;
    for (int i = l; i <= r; ++i)
        f[i] = i;
    for (int i = 2; i <= r; ++i)
    {
        int cnt = 0, fis = 0;

        for (int j = i; j <= r; j += i)
        {
            if (!fis)
                fis = j;
            edge.push_back({fis, j, lcm(fis, j)});
            vis[j] = 1;
        }

        if (i >= l)
            edge.push_back({fis, l, lcm(fis, l)});
    }
    Kruskal();
    return 0;
}