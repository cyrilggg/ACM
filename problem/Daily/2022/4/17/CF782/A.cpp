#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve()
{
    int n, r, b;
    cin >> n >> r >> b;
    if (r < b)
    {
        int cnta = 0, cntb = 0;
        int cnt = (n + r) / (r + 1);
        for (int i = 1; i <= n; i ++ )
        {
            if (i % cnt == 0 && cnta < r) cnta ++, cout << 'R';
            else cout << 'B';
        }
        cout << "\n";
    }
    else
    {
        int cnta = 0, cntb = 0;
        int cnt = (n + b) / (b + 1);
        for (int i = 1; i <= n; i ++ )
        {
            if (i % cnt == 0 && cntb < b) cntb ++, cout << 'B';
            else cout << 'R';
        }
        cout << "\n";
    }
}

signed main()
{
   int _ = 1;
   cin >> _;
   while (_--)
      solve();
}