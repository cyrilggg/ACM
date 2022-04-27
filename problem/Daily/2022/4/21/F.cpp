#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve()
{
    int n;
    cin >> n;
    vector<int>sum(n + 1);
    vector<int>v(n + 1);
    for (int i = 1; i <= n; i ++ )
    {
        cin >> v[i];
        sum[i] = sum[i - 1] + v[i];
    }
    int start;
    for (int i = 1; i <= n; i ++ )
    {
        if (sum[i] * 2 == sum[n])
        {
            cout << n << "\n";
            return;
        }
        else if (sum[i] * 2 > sum[n])
        {
            start = i;
            break;
        }
    }
    int ans = 0;
    for (int i = start, j = start + 1; i >= 1 && j <= n;)
    {
        i --;
        while (j <= n && sum[n] - sum[j - 1] > sum[i]) j ++;
        if (j <= n && (sum[n] - sum[j - 1]) == sum[i])
        {
            ans = i + (n - j + 1);
            break;
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