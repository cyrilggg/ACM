#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define returnNo return void(puts("No"))
#define returnYes return void(puts("Yes"))

void solve()
{
    int n;
    cin >> n;
    vector<int>v(n);
    int cnt = 0;
    for (int i = 0; i < n; i ++ )   cin >> v[i];

    for (int i = n - 1; i >= 1; i -- )
    {
        while (v[i] <= v[i - 1] && v[i - 1])
        {
            cnt ++;
            v[i - 1] /= 2;
        }
    }
    for (int i = 0; i < n - 1; i ++ )
    {
        if (v[i] >= v[i + 1])
        {
            cout << -1 << endl;
            return;
        }
    }
    cout << cnt << endl;
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