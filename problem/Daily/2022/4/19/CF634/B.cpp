#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    int cnt = (a + b - 1) / b;
    int idx = 0;
    for (int i = 0; i < n; i ++ )
    {
        cout << char(idx + 'a');
        idx ++;
        if (idx >= b) idx = 0;
    }
    cout << endl;
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