#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve()
{
    int n, m;
    cin >> n >> m;
    if (n < m) swap(n, m);
    if ((n == 1 && m > 2) || (m == 1 && n > 2)) {
        cout << -1 << endl;
        return;
    }
    cout << (n - 1) * 2 - ((n - m) & 1) << endl;
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