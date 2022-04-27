#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'


void solve()
{
    srand(time(0));
    int seed = rand();
    if (seed & 1) cout << "YES" << endl;
    else cout << "NO" << endl;
}

signed main()
{
   int _ = 1;
   //cin >> _;
   while ( _-- )solve();
}