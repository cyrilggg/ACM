#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1010;
char draw[N][N];
int n, m;

struct Node
{
    int sx,  sy;
    string MAP;
    string STEP;
};

void bfs()
{
    set<string>S;
    queue<Node>q;
    string ans = "", a = "";
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            {
                ans = ans + draw[i][j];
                a = a + '0';
            }
    for (int i = 1; i < n; i ++ )
        for (int j = 1; j < m; j ++ )
        {
            q.push({i, j, a, ""});
        }
        
    while (q.size())
    {
        auto tmp = q.front();
        q.pop();
        cout << tmp.MAP << endl;
        if (tmp.MAP == ans)
        {
            cout << tmp.STEP.size() / 3 << endl;
            for (int i = 0; i < tmp.STEP.size() / 3; i += 3 )
            {
                cout << tmp.STEP[i] << ' ' << tmp.STEP[i + 1] << ' ' << tmp.STEP[i + 2] << endl;
            }
            return;
        }
        char maze[N][N];
        int idx = 0;
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= m; j ++ )
                maze[i][j] = tmp.MAP[idx ++ ];
        
        for (int i = 1; i <= n * m; i ++ )
        {
            maze[tmp.sx][tmp.sy] = maze[tmp.sx + 1][tmp.sy] = maze[tmp.sx][tmp.sy + 1] = maze[tmp.sx + 1][tmp.sy + 1] = i;
        
        string x = "";
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= m; j ++ )
            {
                x = x + maze[i][j];
            }
        if (S.count(x))continue;
        S.insert(x);
        q.push({tmp.sx, tmp.sy, x, tmp.STEP + to_string(tmp.sx) + to_string(tmp.sy) + to_string(i)});
        }
    }
    cout << -1 << endl;
    return;
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ )
    {
        for (int j = 1; j <= m; j ++ )
            cin >> draw[i][j];
    }
    bfs();
}

signed main()
{
   int t = 1;
   //cin >> t;
   while (t -- )solve();
}