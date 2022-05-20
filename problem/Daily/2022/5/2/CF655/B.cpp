#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define endl '\n'
#define returnNo return void(puts("No"))
#define returnYes return void(puts("Yes"))
void solve()
{
    int n;
    cin >> n;
    for (int i = 2; i <= n / i; i ++ )
    {
        if (n % i == 0)
        {
            cout << n / i << ' ' << n - n / i << endl;
            return;
        }
    }
    cout << 1 << ' ' << n - 1 << endl;
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