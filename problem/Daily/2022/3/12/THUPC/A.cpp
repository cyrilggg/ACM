#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>

using namespace std;

#define int long long
typedef long long ll;
ll gcd(ll a, ll b)
{
    if (a % b == 0)
    {
        return b;
    }
    else
    {
        return gcd(b, a % b);
    }
}

ll lcm(ll a, ll b)
{
    return a * b/ gcd(a, b);
}
const int N = 1000010, M = 2000010, INF = 0x3f3f3f3f;

int l, r;
int p[N];
int idx = 1;
struct Edge
{
    int a, b, w;

    bool operator< (const Edge &W)const
    {
        return w < W.w;
    }
}edges[M];

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int kruskal()
{
    sort(edges + 1, edges + idx);

    for (int i = l; i <= r; i ++ ) p[i] = i;    // 初始化并查集

    int res = 0, cnt = 0;
    for (int i = 1; i < idx; i ++ )
    {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        a = find(a), b = find(b);
        if (a != b)
        {
            cout << edges[i].a << ' ' << edges[i].b <<' '<< edges[i].w << endl;
            p[a] = b;
            res += w;
            cnt ++ ;
        }
    }

    return res;
}

signed main()
{
    scanf("%d%d", &l, &r);
    for (int i = l; i <= r; i ++ )
    {
        for (int j = l; j <= r; j ++ )
        {
            if (i == j)continue;
            edges[idx ++ ] = {i, j, lcm(i, j)};
        }

    }
    int t = kruskal();

    cout << t << endl;

    return 0;
}