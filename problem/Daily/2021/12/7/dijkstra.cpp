/*
    Rating : 1500
    问题就叫dijkstra 要预处理前序可以用pre数组实现
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;

const int N = 1e5 + 10, M = 2 * N;
int h[N], e[M], w[M], ne[M], idx;
int dist[N];
bool st[N];
int pre[N];
int n, m;

void add(int a, int b, int c)  // 添加一条边a->b，边权为c
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

void dijkstra()  
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> heap;
    heap.push({0, {1,-1}});

    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();

        int ver = t.second.first;

        if (st[ver]) continue;
        st[ver] = true;
        pre[ver] = t.second.second;
        for (int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[ver] + w[i])
            {
                dist[j] = dist[ver] + w[i];
                heap.push({dist[j],{j, ver}});
            }
        }
    }
}


 main()
{
    memset(h, -1, sizeof h);
    memset(pre, -1, sizeof pre);
    cin >> n >> m ;
    for (int i = 1; i <= m; i ++ )
    {
        int a, b, c, d;
        cin >> a >> b >> c;
        add (a, b, c);
        add (b, a, c);
    }
    dijkstra();
    vector<int> v;
    v.clear();
    if (pre[n] == -1)v.push_back(-1);
    else 
    {
    cout << 1 <<' ';
    for (int i = n; i != 1 ; i = pre[i]) v.push_back(i);
    }for (int i = v.size() - 1; i >= 0; i -- )cout << v[i] << ' ';
    return 0;
}