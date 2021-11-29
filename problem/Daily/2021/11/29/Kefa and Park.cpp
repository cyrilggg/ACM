/*
    Rating : 1500
    ��Ŀ�����ѣ����Ѽ��ɣ���Ҫ�ǳ���һ�����⿨�˺ܾã��ٶȷ���û�з�����������ġ���ֱ���ؿ���д����
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

void add(int a, int b)  // ���һ����a->b
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