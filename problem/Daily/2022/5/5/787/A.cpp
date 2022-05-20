#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define returnNo return void(puts("No"))
#define returnYes return void(puts("Yes"))

void solve()
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    x -= a, y -= b;
    if (x < 0) x = 0;
    if (y < 0) y = 0;
    if (x + y > c) returnNo;
    else returnYes;
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