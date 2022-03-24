#include <bits/stdc++.h>
using namespace std;
const int  N = 1e5 + 10, M = 2 * N;
#define int long long

int h[N], e[M], ne[M], idx;
int w[N], dist[N], st[N];
int n, m, d;

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

bool check(int x)
{
    memset(st, 0, sizeof st);
    queue<pair<int,int>>q;
    q.push({1, 0});
    while(q.size())
    {
        auto t = q.front();
        q.pop();
        if (t.first == n) return t.second >= d;
        
        int ver = t.first;
        if (st[ver]) continue;
        st[ver] = 1;
        
        for (int i = h[ver]; ~i; i = ne[i])
        {
            int j = e[i];
             cout << x << ' ' << ver <<' '<< i <<' '<<j<< endl;
            if (w[i] > x) continue;
            q.push({j, t.second + 1});
        }
    }
    return true;
}

signed main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m >> d;
    int l = 1e12, r = -1e12;
    for (int i = 1; i <= m; i ++ )
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        l = min(l, c);
        r = max(r, c);
    }
    
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    
    cout << l - 1 << endl;
}