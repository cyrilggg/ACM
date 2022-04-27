#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define returnNo return void(puts("No"))
#define returnYes return void(puts("Yes"))
void solve()
{
    int idx = 1;
    int n, k;
    cin >> n >> k;
    vector<int>a(n);
    int ans = 0;
    for (int i = 0; i < n; i ++ ){
        cin >> a[i];
    }
    int l = *min_element(a.begin(), a.end());
    int r = *max_element(a.begin(), a.end());
    for (int i = 0; i < n - 1; i ++ ){
        ans += abs(a[i] - a[i + 1]);
    }

    ans += min((l - 1) * 2, min(a[0], a[n - 1]) - 1);
    if (k > r)
        ans += min((k - r) * 2, k - max(a[0], a[n - 1]));
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