#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    vector<int> v(n + 1);
    vector<int> sum[210];
    vector<int> pos[210];
    for (int i = 1; i <= 200; i++)
        pos[i].clear();
    for (int i = 1; i <= 200; i++)
        sum[i].resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        pos[v[i]].push_back(i);
    }

    for (int i = 1; i <= 200; i++)
        for (int j = 1; j <= n; j++)
            sum[i][j] = sum[i][j - 1] + (v[j] == i);
        
    
    for (int i = 1; i <= 200; i++)
    {
        ans = max(ans, (int)pos[i].size());
        // for (int j = 1; j <= n; j ++ ) cout << sum[j][i] << " \n"[j == n];
        for (int j = 0, k = pos[i].size() - 1; j < k; j++, k--)
        {
            int l = pos[i][j], r = pos[i][k];
            // cout << l << ' ' << r <<' '<< i << endl;
            for (int s = 1; s <= 200; s++)
            {
                // if (!(sum[r - 1][s] - sum[l][s])) continue;
                // cout << i << ' ' << s << ' ' <<' '<<r << ' ' << l << ' ' << sum[r - 1][s] - sum[l][s] << endl;
                ans = max(ans, 2 * (j + 1) + sum[s][r - 1] - sum[s][l]);
            }
        }
    }
    cout << ans << endl;
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