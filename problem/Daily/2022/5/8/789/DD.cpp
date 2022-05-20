#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define endl '\n'
#define returnNo return void(puts("No"))
#define returnYes return void(puts("Yes"))
void solve()
{
    int n;
    scanf("%d", &n);
    vector<int>v(n);
    vector<vector<int>>f(n, vector<int>(n + 1)), sum(n, vector<int>(n + 1));
    map<int,int>mp;
    for (int i = 0 ; i < n; i ++ ) 
    {
        scanf("%d", &v[i]);
        mp[v[i]] = i;
    }
    //f[i][j] 表示 第 i 个位置 小于 j 个的个数
    for (int i = n - 1; i >= 0; i -- )
    {
        for (int j = 1; j <= n; j ++ )
        {
            if (i < n - 1) f[i][j] += f[i + 1][j];
            if (v[i] < j) f[i][j] ++;
        }
    }

    for (int i = n - 1; i >= 0; i -- ) 
    {
        for (int j = i - 1; j >= 0; j -- )
        {
            sum[i][j] = sum[i][j + 1] + f[i][v[j]] - (v[i] < v[j]);
            //cout << i << ' ' << j << ' ' << sum[i][j] << ' ' <<  f[i][v[j]] - (v[i] < v[j]) << endl;
        }
    }
 
    long long ans = 0;
    int minn = 1, maxn = n;
    for (int i = 0; i < n; i ++ )
    {
        for (int j = maxn; j > v[i]; j -- )
        {
            if (mp[j] < i) continue;
            ans += sum[mp[j]][i + 1];
        }
    }
    cout << ans << endl;
}
 
signed main()
{
   int _ = 1;
   cin >> _;
   while (_--)
      solve();
}