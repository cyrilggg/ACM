#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int N = 11000, M = 500010;

int n, m;
int p[N];
int d[N];
int ans, id, mi, X, Y;
int h[N], e[M], ne[M], idx, siz[N], w[M], vis[N];

void add(int a, int b, int c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}

struct Edge
{
    int a, b, w;
    bool operator<(const Edge &W) const
    {
        return w < W.w;
    }

} edges[M];

int Find(int x)
{
    return x == p[x] ? x : p[x] = Find(p[x]);
}



void get(int x, int fa) {
    siz[x] = 1;
    for(int i = h[x]; ~i; i = ne[i]) {
        int v = e[i], ww = w[i];
        if(vis[i] || v == fa) continue;
        get(v, x);
        siz[x] += siz[v];
        if(ww < mi) {
            mi = ww;
            id = i;
            Y = v, X = x;
        }
    }
}
 
long long dfs(int x) {
    bool flag = 0;
    for(int i = h[x]; ~i; i = ne[i]) {
        if(vis[i]) continue;
        flag = 1;
        break;
    }
    if(!flag) return 0;
    mi = 1e9, id = 0;
    get(x, -1);
    vis[id] = 1, vis[id ^ 1] = 1;
    long long num = 1ll * (siz[x] - siz[Y]) * siz[Y] * mi;
    int _x = X, _y = Y;
    return num + dfs(_x) + dfs(_y);
}

bool check(int pos, bool flag) {
    for(int i = 1; i <= n; ++i) p[i] = i;
    int cnt = 0;
    for(int i = pos; i <= m; ++i) {
        int xx = Find(edges[i].a);
        int yy = Find(edges[i].b);
        int ww = edges[i].w;
        if(xx != yy) {
            p[xx] = yy;
            ///只对最后一次建图
            if(flag) {
                add(edges[i].a, edges[i].b, ww);
                add(edges[i].b, edges[i].a, ww);
            }
            cnt++;
        }
        if(cnt >= n - 1) return 1;
    }
    return 0;
}
 
int lower_bound(int l, int r) {
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (check(mid, 0)) l = mid;
        else r = mid - 1;
    }
    return l;
}
 
signed main() {
    memset(h, -1, sizeof h);

    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; ++i)
        scanf("%d%d%d", &edges[i].a, &edges[i].b, &edges[i].w);
    sort(edges + 1, edges + m + 1);
    int minn = lower_bound(1, m);
    check(minn, 1);
    printf("%lld\n", dfs(1));
    return 0;
}
// bool check(int x, bool flag)
// {
//     for (int i = 1; i <= n; i ++ )  p[i] = i;
//     vector<Edge>cnt;
//     for (int i = x; i < m; i ++ )
//     {
//         //if (edges[i].w < x) continue;
//         int a = edges[i].a, b = edges[i].b, ww = edges[i].w;
//         int aa = Find(a), bb = Find(b);
//         if (aa != bb)
//         {
//             p[aa] = bb;
//             cnt.push_back({a, b, ww});
//         }
//     }
//    // cout << cnt.size() << ' ' << x << endl;
    
//     if (cnt.size() >= n - 1)
//     {
//         if (flag)
//         {
//             for (auto v : cnt)
//             {
//                 add(v.a, v.b, v.w);
//                 add(v.b, v.a, v.w);
//             }
//         }
//         // sort(cnt.begin(), cnt.end());
//         // reverse(cnt.begin(), cnt.end());
//         // for (int i = 0; i < cnt.size(); i ++ )
//         // {
//         //     //cout << cnt[i] << ' ' << i << endl;
//         //     ans += (i + 1) * cnt[i];
//         // }
//         return 1;
//     }
//     else return false;

// }

// signed main()
// {
//     memset(h, -1, sizeof h);
//    scanf("%lld%lld", &n, &m);

//     for (int i = 0; i < m; i++)
//     {
//         int a, b, w;
//         scanf("%lld%lld%lld", &a, &b, &w);
//         edges[i] = {a, b, w};
//     }
//     sort(edges, edges + m);
//     int l = 0, r = m - 1;
//     while (l < r)
//     {
//         int mid = (l + r + 1)>> 1;
//         if (check(mid, 0)) l = mid;
//         else r = mid - 1;
//     }
//     check(l, 1);
//     //dfs(1);
//     cout << dfs(1) << endl;
//     return 0;
// }