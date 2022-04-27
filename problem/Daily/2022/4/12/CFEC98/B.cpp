#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve()
{
    int n;
    cin >> n;
    int maxn = -1, sum = 0;
    for (int i = 1; i <= n ; i ++ )
    {
        int x;
        cin >> x;
        maxn = max(maxn, x);
        sum += x;
    }
    cout << max((sum + (n - 2)) / (n - 1), maxn) * (n - 1) - sum << endl;
}

signed main()
{
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
}