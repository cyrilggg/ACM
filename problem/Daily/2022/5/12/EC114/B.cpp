#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define returnNo return void(puts("No"))
#define returnYes return void(puts("Yes"))

void solve()
{
    int a, b, c, m;
    cin >> a >> b >> c >> m;
    if (max(a - 1, 0ll) + max(b - 1, 0ll) + max(c - 1, 0ll) < m) returnNo;
    if (max(2 * max({a, b, c}) - a - b - c - 1, 0ll) > m) returnNo;
    returnYes;
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