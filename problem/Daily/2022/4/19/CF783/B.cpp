#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define returnNo return void(puts("NO"))
#define returnYES return void(puts("YES"))
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int>v(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i ++ )
    {
        cin >> v[i];
    }
    sort(v.begin() + 1, v.end());
    for (int i = 1; i < n; i ++ )
    {
        sum += 1 + max(v[i + 1], v[i]);
    }
    sum += 1 + max(v[n], v[1]);
    //cout << sum << endl;
    if (sum <= m) returnYES;
    else returnNo;
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