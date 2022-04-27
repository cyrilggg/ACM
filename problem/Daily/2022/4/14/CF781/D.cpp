#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve()
{
    int ans = 0;
    for (int i = 0; i < 30; i ++ )
    {
        int res = (1 << i) - ans;
        cout << '?' <<' '<< res << ' ' << (1 << i + 1) + res << endl;
        int x;
        cin >> x;
        if (x == (1 << (i + 1))) ans += 1 << i; 
    }
    cout << '!' <<' '<< ans << endl;
}

signed main()
{
   int _ = 1;
   cin >> _;
   while (_--)
      solve();
}