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
    int cnt = 0;
    for (int i = 0; i < a.size();)
    {
        if (a[i] == 'a')
        {
            cnt = 0;
            while (i < a.size() && a[i] == 'a')
                i++, cnt++;
            if (cnt < 2)
                returnNo;
        }
        else
        {
            cnt = 0;
            while (i < a.size() && a[i] == 'b')
            {
                i ++ ;
                cnt ++;
            }
            if (cnt < 2) returnNo;
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