#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve()
{
    int x;
    cin >> x;
    if (x < 1400) cout << "Division 4\n";
    else if (x < 1600) cout << "Division 3\n";
    else if (x < 1900) cout << "Division 2\n";
    else cout << "Division 1\n";
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