#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    int maxn = -1, lexn = -1;
    for (int i = 1; i <= n; i ++ )
    {
        int x;
        cin >> x;
        if (x > maxn)
        {
            lexn = maxn;
            maxn = x;
        }
        else if (x > lexn)
        {
            lexn = x;
        }
    }
    cout << maxn + lexn << endl;
}

signed main()
{
   int t = 1;
   //cin >> t;
   while (t -- )solve();
}