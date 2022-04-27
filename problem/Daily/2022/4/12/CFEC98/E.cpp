#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int,int>>v(m);
    
    for (int i = 0; i < m; i ++ )
    {
        cin >> v[i].first >> v[i].second;
        v[i].first--;
    }
    
    sort(v.begin(), v.end(), 
        [](const pair<int,int> &a, const pair<int,int> &b)
        {
            return a.first + a.second < b.first + b.second;
        });// 中点排序

    vector<int>su(m + 1);//后缀
    for (int i = 0; i < n - k + 1; i ++ )
    {
        int cur = 0;
        for (int j = m - 1; j >= 0; j -- )
        {
            cur += max(0 * 1ll, min(i + k, v[j].second) - max(i, v[j].first));
            su[j] = max(su[j], cur);//当前最大a[i]
        }
    }
    
    int ans = su[0];
    //前缀
    for (int i = 0; i < n - k + 1; i ++ )
    {
        int cur = 0;
        for (int j = 0; j < m; j ++ )
        {
            cur += max(0 * 1ll, min(i + k, v[j].second) - max(i, v[j].first));
			ans = max(ans, cur + su[j + 1]);
        }
    }
    
    cout << ans << endl;
}

signed main()
{
   int _ = 1;
   //cin >> _;
   while (_--)
      solve();
}