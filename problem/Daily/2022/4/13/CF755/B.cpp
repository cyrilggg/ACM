#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve()
{
    int n, m;
    cin >> n >> m;
    cout << min({((n + 2) / 3) * m,
                 ((m + 2)/ 3) * n,
                 m * (n / 3) + (n % 3) * ((m + 2) / 3),
                 n * (m / 3) + (m % 3) * ((n + 2) / 3)})  << endl;   
}

signed main()
{
   int _ = 1;
   cin >> _;
   while (_--)
      solve();
}