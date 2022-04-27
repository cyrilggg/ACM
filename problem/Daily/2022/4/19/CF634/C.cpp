#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve()
{
    int n;
    cin >> n;
    map<int,int>cnt;
    int cnta = 0, maxn = -1;
    for (int i = 0; i < n; i ++ )
    {
        int x;
        cin >> x;
        cnt[x] ++;
    }
    for (auto &[a, b] : cnt)
    {
        cnta ++;
        maxn = max(maxn, b);
    }
    cout << min(maxn, cnta) - (maxn == cnta) << endl;
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