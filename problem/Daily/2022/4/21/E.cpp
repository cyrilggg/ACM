#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 1e5 + 10;
int sum[N][26];

void solve()
{
    int n;
    cin >> n;
    map<string,int>mp;
    int ans = 0;

   for (int i = 1; i <= n; i ++ )
    {
        string a;
        cin >> a;
        for (char j = 'a'; j <= 'k'; j ++ )
        {
            if (j != a[0]) ans += mp[string(1, j) + string(1, a[1])];
            if (j != a[1]) ans += mp[(string(1, a[0]) + string(1, j))];
        }
        mp[a] ++;
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