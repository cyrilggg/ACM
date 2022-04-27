#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve()
{
    string ans[10];
    for (int i = 1; i < 10; i ++ )
    {
        cin >> ans[i];
        for (int j = 0; j < ans[i].size(); j ++ )
        {
            if (ans[i][j] == '2') ans[i][j] = '1';
        }
    }
    for (int i = 1; i < 10; i ++ )
        cout << ans[i] << "\n";
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