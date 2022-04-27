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
    for (int i = 0; i < n; i ++ ){
        cin >> v[i];
    }
    vector<int>ans(n);
    ans[0] = v[n - 1];
    for (int i = 1; i < n; i ++ ){
        ans[i] = v[i - 1];
    }
    for (int i = 0; i < n; i ++ )cout << ans[i] << " \n"[i == n - 1];

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