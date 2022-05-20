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
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    if (n & 1)
    {
        for (int i = 0; i < n - 2; i++)
        {
            if (i & 1 && i < n - 3)
            {
                if (v[i] > v[i + 2] || v[i] > v[i + 3])
                {
                    returnNo;
                }
            }
            else if (!(i & 1) && i < n - 2)
            {
                if (v[i] > v[i + 1] || v[i] > v[i + 2])
                {
                    returnNo;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < n - 2; i++)
        {
            if (!(i & 1) && i < n - 3)
            {
                if (v[i] > v[i + 2] || v[i] > v[i + 3])
                {
                    returnNo;
                }
            }
            else if ((i & 1) && i < n - 2)
            {
                if (v[i] > v[i + 1] || v[i] > v[i + 2])
                {
                    returnNo;
                }
            }
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