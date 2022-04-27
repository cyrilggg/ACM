#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve()
{
    int n;
    cin >> n;
    if (n & 1) cout << 2 << endl;
    else
    {
        int cnt = 1;
        while (n % 2 == 0)
        {
            n >>= 1;
            cnt <<= 1;
        }
        if (n == 1) cout << -1 << endl;
        else cout << min(cnt, n) << endl;
    }
}

signed main()
{
   int t = 1;
   cin >> t;
   while (t -- )solve();
}