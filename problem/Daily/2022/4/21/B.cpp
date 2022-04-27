#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve()
{
    int n;
    cin >> n;
    map<int,int>mp;
    for (int i = 0; i < n; i ++ )
    {
        int x;
        cin >> x;
        mp[x] ++;
    }
    int ans = -1;
    for (auto &[a, b] : mp)
    {
        if (b >= 3)
        {
            ans = a;
            break;
        }
    }
    cout << ans << "\n";
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