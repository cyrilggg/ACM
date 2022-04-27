#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define returnNo return void(puts("NO"))
#define returnYes return void(puts("Yes"))
void solve()
{
    int n;
    cin >> n;
    string a;
    cin >> a;
    if (n == 1 && a[0] != 'W') returnNo;
    int last = 0;
    int final = n + 1;
    a = "x" + a;
    vector<int>sum(n + 1);
    for (int i = 1; i <= n; i ++ )
    {
        sum[i] = sum[i - 1] + (a[i] == 'B');
    }
    for (int i = 1 ; i <= n; i ++ )
    {
        if (a[i] == 'W')
        {
            if (i - last == 2) returnNo;
            else if (i - last > 2 && ((sum[i - 1] - sum[last]) == (i - last - 1) || (sum[i - 1] - sum[last]) == 0))
            {
                //cout << sum[i - 1] - sum[last] <<' '<< i << ' ' << last <<  endl; 
                returnNo;
            }
            last = i;
        }
        
    }
    if (final - last == 2) returnNo;
    else if (final - last > 2 && ((sum[final - 1] - sum[last]) == (final - last - 1) || (sum[final - 1] - sum[last]) == 0))
            {
                //cout << sum[i - 1] - sum[last] <<' '<< i << ' ' << last <<  endl; 
                returnNo;
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