#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    int ans = 1e18;
    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        int tmp = 0;
        for (int j = i - 1; j > 0; j--)
        {
            cnt += tmp / v[j] + 1;
            tmp = (tmp / v[j] + 1) * v[j];
        }
        tmp = 0;
        for (int j = i + 1; j <= n; j++)
        {
            cnt += tmp / v[j] + 1;
            tmp = (tmp / v[j] + 1) * v[j];
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--)
        solve();
}