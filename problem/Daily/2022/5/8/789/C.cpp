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
    string a;
    cin >> a;
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < n - 1; i += 2)
    {
        if (a[i] != a[i + 1])
        {
            a[i] = a[i + 1] = '2';
            ans1 ++;
        }
    }
    char last = '2';
    for (int i = 0; i < n; i ++ )
    {
        if (a[i] != last && a[i] != '2')
        {
            ans2 ++;
            last = a[i];
        }
    }
    cout << ans1 << ' ' << max(1ll, ans2) << endl;
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