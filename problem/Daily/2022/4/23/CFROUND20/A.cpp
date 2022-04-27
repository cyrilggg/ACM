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
    int ans = 0;
    for (int i = 1; i <= n; i ++ ){
        int x;
        cin >> x;
        ans += (x - 1);
    }
    if (ans & 1) cout << "errorgorn" << endl;
    else cout << "maomao90" << endl;
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