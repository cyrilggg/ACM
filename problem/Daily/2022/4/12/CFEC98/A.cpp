#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve()
{
    int a, b;
    cin >> a >> b;
    int ans = max(a, b) * 2;
    if (a != b) ans --;
    cout << ans << endl;
}

signed main()
{
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
}