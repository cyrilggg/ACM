#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve()
{
    int n;
    cin >> n;
    vector<int>cnt(n + 1);
    for (int i = 1; i <= n; i ++ ) 
    {
        int x;
        cin >> x;
        cnt[x] ++;
    }
    vector<int>S;
    int ans = 0;
    for (int i = 0; i <= n; i ++ )
    {
        if (ans == -1)
        {
            cout << -1 << " \n"[i == n];
            continue;
        }
        cout << ans + cnt[i] << " \n"[i == n];
        while (cnt[i] -- )
        {
            S.push_back(i);
        }
        if (S.empty())
        {
            ans = -1;
        }
        else
        {
            ans += i - S.back();
            S.pop_back();
        }
    }
}

signed main()
{
   int _ = 1;
   cin >> _;
   while (_--)
      solve();
}