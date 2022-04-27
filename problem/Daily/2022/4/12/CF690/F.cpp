#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve()
{
    vector<int> L, R;
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i ++ )
    {   
        cin >> v[i].first >> v[i].second;
        L.push_back(v[i].first);
        R.push_back(v[i].second);
    }
    sort(L.begin(), L.end());
    sort(R.begin(), R.end());
    int ans = n - 1;
    for (int i = 0; i < n; i ++ )
    {
        int l = lower_bound(R.begin(), R.end(), v[i].first) - R.begin();
        int r = max(0 * 1ll, n - (int)(upper_bound(L.begin(), L.end(), v[i].second) - L.begin()));
        ans = min(ans, l + r);
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