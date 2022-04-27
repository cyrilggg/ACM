#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int N = 11000, M = 500010;

int n, m;
int p[N];
int d[N];

struct Edge
{
    int a, b, w;
    bool operator<(const Edge &W) const
    {
        return w < W.w;
    }
    bool operator>(const Edge &W) const
    {
        return w >= W.w;
    }
} edges[M];

int Find(int x)
{
    if (p[x] != x)
        p[x] = Find(p[x]);
    return p[x];
}

void kruskal()
{
    sort(edges, edges + m);
    priority_queue<Edge, vector<Edge>, greater<Edge>> heap,eap;

    for (int i = 1; i <= n; i++)
        p[i] = i; // 初始化并查集

    for (int i = 0; i < m; i++)
    {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        int aa = Find(a), bb = Find(b);
        if (aa != bb)
        {
            p[aa] = bb;
            heap.push({a, b, w});
            d[a]++;
            d[b]++;
        }
        else
        {
            //cout <<"==="<< a << ' ' << b << ' ' << w << endl;
            auto TOP = heap.top();
           // cout <<"=="<<TOP.a <<' '<<TOP.b<<' '<<TOP.w<<endl;
            if (a != TOP.a && a != TOP.b && b != TOP.a && b != TOP.b)
            {
                //cout <<"done"<<endl;
                if (d[TOP.a] >= 2 && d[TOP.b] >= 2)
                {
                    eap.push(TOP);
                    heap.pop();
                    d[TOP.a]--, d[TOP.b]--;
                    heap.push({a, b, w});
                    d[a]++, d[b]++;
                }
            }
            else if ((a == TOP.a && b == TOP.b) || (a == TOP.b && b == TOP.a))
            {
                //cout << "h"<<endl;
                eap.push(TOP);
                heap.pop();
                heap.push({a, b, w});
            }
            else if ((a != TOP.a && a != TOP.b))
            {
                //cout <<"here"<<endl;
                if (b == TOP.a)
                {
                    //cout << "===="  << a << ' ' << b << ' ' << w << endl;

                    if (d[TOP.b] >= 2)
                    {
                        eap.push(TOP);
                        heap.pop();
                        d[TOP.b]--;
                        d[a]++;
                        heap.push({a, b, w});
                    }
                }
                if (b == TOP.b)
                {
                    if (d[TOP.a] >= 2)
                    {
                        eap.push(TOP);
                        heap.pop();
                        d[TOP.a]--;
                        d[a]++;
                        heap.push({a, b, w});
                    }
                }
            }
            else
            {
                //cout<<"hi"<<endl;
                if (a == TOP.a)
                {
                    if (d[TOP.b] >= 2)
                    {
                        eap.push(TOP);
                        heap.pop();
                        d[TOP.b]--;
                        d[b]++;
                        heap.push({a, b, w});
                    }
                }
                if (a == TOP.b)
                {
                    if (d[TOP.a] >= 2)
                    {
                        eap.push(TOP);
                        heap.pop();
                        d[TOP.a]--;
                        d[b]++;
                        heap.push({a, b, w});
                    }
                }
            }
        }
    }
    int idx = n - 1;
    int res = 0;
    while (eap.size())
    {
        while(eap.size() && eap.top().w != heap.top().w) eap.pop();
        while (eap.size())
        {
            heap.push(eap.top());
            eap.pop();
        }
    }
    set<pair<int,int>>S;
    while (idx)
    {
        //cout << heap.top().a <<' ' << heap.top().b << ' ' << heap.top().w << endl;
        if(S.count({heap.top().a, heap.top().b}))
        {
            for (int i =0;; i ++);
        }
        S.insert({heap.top().a, heap.top().b});
        S.insert({heap.top().b, heap.top().a});
        
        res += heap.top().w * idx --;
        heap.pop();
    }
    cout << res << endl;
}

signed main()
{
    scanf("%lld%lld", &n, &m);

    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        scanf("%lld%lld%lld", &a, &b, &w);
        edges[i] = {a, b, w};
    }

    kruskal();
    return 0;
}