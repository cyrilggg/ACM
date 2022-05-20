#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define returnNo return void(puts("No"))
#define returnYes return void(puts("Yes"))
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int>v(n + 1), b(n + 1);
    for (int i = 1; i <= n; i ++ )
    {
        cin >> v[i];
        b[i] = v[i];
    }
    sort(b.begin() + 1, b.end());
    for (int i = 1; i <= n; i ++ )
    {
        if (b[i] != v[i])
        {
            if (!(i - 1 >= k || n - i >= k)) returnNo;
        }
    }
    returnYes;
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