#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int>v(31);
    for (int i = 0; i < n; i ++ )
    {
        int x;
        cin >> x;
        int cnt = 0;
        while (x)
        {
            if (x & 1) v[cnt]++;
            x >>= 1;
            cnt ++;
        }
    }
    int ans = 0;
    for (int i = 30; i >= 0; i -- )
    {
        if (k >= n - v[i])
        {
            //cout << i << ' ' << v[i] << endl;
            ans += (1 << i);
            k -= (n - v[i]);
        }
    }
    cout << ans << endl;
}

signed main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   int _ = 1;
   cin >> _;
   while (_--)
      solve();
}