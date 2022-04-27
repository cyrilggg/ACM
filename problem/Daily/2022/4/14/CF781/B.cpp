#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve()
{
    int n;
    cin >> n;
    map<int,int>mp;
    int maxx = -1;
    for (int i = 0; i < n; i ++ )
    {
        int x;
        cin >> x;
        mp[x] ++;
        if (mp[x] > maxx)
        {
            maxx = mp[x];
        }
    }
    int k = 0;
    while ((maxx << k) < n)
        k ++;
    cout << k + (n - maxx) << endl;
}

signed main()
{
   int _ = 1;
   cin >> _;
   while (_--)
      solve();
}