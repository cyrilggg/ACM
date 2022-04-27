#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve()
{
    int u, v;
    cin >> u >> v;
    cout << - u * u << ' ' << v * v << '\n';
}

signed main()
{
   int _ = 1;
   cin >> _;
   while (_--)
      solve();
}