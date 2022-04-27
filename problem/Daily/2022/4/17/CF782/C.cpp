#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 2e5 + 10;
int x[N], s[N];
int n, a, b;

void solve()
{
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
        s[i] = s[i - 1] + x[i];
    }
    int ans = 1e18;
    for (int i = 0; i <= n; i ++ )
    {
        ans = min(ans, 1ll * (a + b) * x[i] + b * 1ll * (s[n] - s[i] - 1ll * (n - i) * x[i]));
    }

    cout << ans << endl;
}

signed main()
{
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
}