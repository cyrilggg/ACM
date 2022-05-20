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
    int cnt = 0;
    bool flag = true;
    int ans = 0;
    for (int i = 0; i < n;)
    {
        if (a[i] == '0')
        {
            while (i < n && a[i] == '0')
            {
                i++;
                cnt++;
            }
            
            if (cnt & 1)
            {
                if (i < n)
                {
                    a[i] = '0';
                    ans++;
                }
                else
                    flag = false;
            }
        }
        else
        {
            while (i < n && a[i] == '1')
            {
                i++;
                cnt++;
            }
            if (cnt & 1)
            {
                if (i < n)
                {
                    a[i] = '1';
                    ans ++;
                }
                else
                    flag = false;
            }
        }
    }
    if (!flag)
    {
        ans = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            cnt = 0;
            if (a[i] == '0')
            {
                while (i >= 0 && a[i] == '0')
                {
                    i--;
                    cnt++;
                }
                if (cnt & 1)
                {
                    if (i >= 0)
                    {
                        a[i] = '0';
                        ans++;
                    }
                    else
                        flag = false;
                }
            }
            else
            {
                while (i >= 0 && a[i] == '1')
                {
                    i--;
                    cnt++;
                }
                if (cnt & 1)
                {
                    if (i >= 0)
                    {
                        a[i] = '1';
                        ans ++;
                    }
                    else
                        flag = false;
                }
            }
        }
    }
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