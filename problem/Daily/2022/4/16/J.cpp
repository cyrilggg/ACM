#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 210;
int a[N][N], fa[N][N], dp[N][N];
int n;
int ans[N];

int get(int i, int j) {
	int k = fa[i][j];
    
    //cout << i<< ' ' << j <<' '<< k << endl;
	if (i <= k - 1) ans[get(i, k - 1)] = k;
	if (k + 1 <= j) ans[get(k + 1, j)] = k;
	return k;
}

int cal(int x, int y, int xx, int yy)
{
    if (x > xx || y > yy) return 0;
    return a[xx][yy] - a[x - 1][yy] - a[xx][y - 1] + a[x - 1][y - 1];
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
        {
            cin >> a[i][j];
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    
    for (int i = 1; i <= n; i ++ )
        for (int j = i; j <= n; j ++ )
            dp[i][j] = 1e15;
    for (int len = 1; len <= n; len ++ )
    {
        for (int i = 1; i + len - 1 <= n; i ++ )
        {
            int j = i + len - 1;
            for (int k = 1; k <= j; k ++ )
            {
                int v = dp[i][k - 1] + dp[k + 1][j] + 
				cal(i, 1, k - 1, i - 1) + cal(i, k, k - 1, n) + 
				cal(k + 1, 1, j, k) + cal(k + 1, j + 1, j, n);
                cout << i << ' ' << j << ' ' << v << endl;
                if (v <= dp[i][j]) {
					dp[i][j] = v;
					fa[i][j] = k;
                    //cout << i << ' ' << j << ' ' << fa[i][j] << endl;
				}
            }
        }
    }
    get(1, n);
    for (int i = 1; i <= n; i ++ )
        cout << ans[i] << " \n"[i == n];
}

signed main()
{
   int _ = 1;
   //cin >> _;
   while (_--)
      solve();
}