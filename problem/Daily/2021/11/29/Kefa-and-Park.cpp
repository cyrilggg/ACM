/*
    Rating : 1500
    题目本身不难，深搜即可，主要是吃了一波读题卡了很久，百度翻译没有翻译出“连续的”，直到回看才写出来
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
const int N = 2e5 + 10, M = 2 * N;

int n, m;
bool vis[N],viss[N];
int h[N], e[M], ne[M], idx;

void add(int a, int b)  // 添加一条边a->b
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

int cnt;

void dfs(int root, int cat)
{
    if(cat > m)return;
    viss[root] = 1;
    bool check = 0;
    for (int i = h[root]; ~i; i = ne[i] )
    {
        int j = e[i];
        if (!viss[j])
        {
            check = 1;
            if (vis[j]) dfs(j , cat + 1);
            else dfs(j, 0);
        }
    }
    if(!check)cnt ++;
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ )
        cin >> vis[i];
    for (int i = 1; i < n; i ++ )
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    dfs(1, vis[1]);
    cout << cnt << endl;
    return 0;
}