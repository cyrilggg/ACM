#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 2010;
char ma[N][N];
int n;

int cal(int x, int y)
{
    int res = 0;
    bool flag = true;
    bool st = true;
    int j = y;
    for (int i = x; st || i != x; i ++ )
    {
        if (i == n + 1) i = 1; 
        if (ma[i][j] == '1') res ++;
        j ++;
        if (j == n + 1) j = 1;
        st = false;
        cout << i << ' ' <<j << endl;
    }
    return res;
}

void solve()
{
   cin >> n;
   int cnt = 0;
   for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
        {
            cin >> ma[i][j];
            if (ma[i][j] == '1') cnt ++;
        }
    int maxn = 0;
    for (int i = 1; i <= n; i ++ )
    {
        int count = cal(i, 1);
        maxn = max(count, maxn);
    }
    cout << cnt - n + 2 * maxn << endl;
}

signed main()
{
   int _ = 1;
   cin >> _;
   while ( _-- )solve();
}