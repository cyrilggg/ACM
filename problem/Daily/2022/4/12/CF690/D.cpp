#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve()
{
    int n;
    cin >> n;
    int sum = 0;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }
    for (int i = n; i >= 1; i--)
    {
        if ((sum % i) == 0)
        {
            bool flag = true;
            int cur = 0;
            for (int j = 0; j < n; j++)
            {
                cur += v[j];
                if (cur > (sum / i))
                {
                    flag = false;
                    break;
                }
                if (cur == (sum / i))
                    cur = 0;
            }
            if (flag)
            {
                cout << n - i << endl;
                return;
            }
        }
    }
}

signed main()
{
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
}