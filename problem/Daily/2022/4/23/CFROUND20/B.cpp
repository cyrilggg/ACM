#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define returnNo return void(puts("No"))
#define returnYes return void(puts("Yes"))
void solve()
{
    string a;
    cin >> a;
    int cntb = 0, cnta = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == 'B')
        {
            cntb++;
        }
        else
            cnta++;
        if (cntb > cnta)
            returnNo;
    }
    if (a[a.size() - 1] != 'B' || cntb > cnta)
        returnNo;
    if (cntb == 0)
        returnNo;
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