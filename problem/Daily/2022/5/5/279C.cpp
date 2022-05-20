#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define returnNo return void(puts("No"))
#define returnYes return void(puts("Yes"))

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<int> l(n), r(n);
    l[0] = 0;
    for (int i = 1; i < n; ++i)
        if (v[i - 1] >= v[i])
            l[i] = l[i - 1];

    r[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; --i)
        if (v[i] <= v[i + 1])
            r[i] = r[i + 1];

    while (m--)
    {
        int ll, rr;
        cin >> ll >> rr;
        --ll;
        --rr;
        cout << (l[rr] <= r[ll] ? "Yes" : "No") << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--)
        solve();
}