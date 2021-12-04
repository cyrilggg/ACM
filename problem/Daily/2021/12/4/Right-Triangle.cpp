/*
    Rating : 1600
    读题浪费了时间，最后弄懂不难，其实可以用两个前缀和就好，这里还麻烦了一些，反正 依次统计每个星四个方向的星星个数分别乘就好
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
const int N = 1010;
int g[N][N];
int n, m;
int ans = 0;
int d[N][N], u[N][N],r[N][N], l[N][N];
void cnt(int x, int y)
{
    int rr = r[x][m] - r[x][y];
    int ll = l[x][1] - l[x][y];
    int uu = u[1][y] - u[x][y];
    int dd = d[n][y] - d[x][y];
    //cout << rr <<' '<<ll <<' '<<uu<<' '<<dd<<endl;
    ans +=  rr * dd + rr * uu + ll * dd + ll * uu;
}

signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ )
    {
        for(int j = 1; j <= m; j ++ )
        {
            char x;
            cin >> x;
            if (x == '*')g[i][j] = 1;
            else g[i][j] = 0;
        }
    }
    
    for (int i = 1; i <= n; i ++ )
    {
        for (int j = 1; j <= m; j ++ )
        {
            r[i][j] = r[i][j - 1] + g[i][j];
        }
        for (int j = m; j >= 1; j -- )
        {
            l[i][j] = l[i][j + 1] + g[i][j];
        }
    }
    
    for (int j = 1; j <= m; j ++ )
    {
        for (int i = 1; i <= n; i ++ )
        {
            d[i][j] = d[i - 1][j] + g[i][j];
        }
        for (int i = n; i >= 1; i -- )
        {
            u[i][j] = u[i + 1][j] + g[i][j];
        }
    }

    for (int i = 1; i <= n; i ++ )
        for(int j = 1; j <= m; j ++ )
            if(g[i][j] == 1)
                cnt(i, j);
            
    cout << ans << endl;
    return 0;
}