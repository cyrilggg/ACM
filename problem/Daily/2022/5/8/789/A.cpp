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
    int cnt0 = 0;
    int ans = 0;
    bool f = 0;
    for (int i = 0; i < n; i ++ )
    {
        cin >> v[i];
        if (v[i] == 0) cnt0 ++;
    }
    sort(v.begin(), v.end());
    for (int i = 1; i < n; i ++ )
    {
        if (v[i] == v[i - 1]) f = 1;
    }
    if (cnt0)
    {
        ans = n - cnt0;
    }
    else if (f) ans = n;
    else ans = n + 1;
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