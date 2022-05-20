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
    int one = 0, zero = a.size() - 1;
    int q = 0;
    int cnt1 = 0, cnt0 = 0;
    for (int i = 0; i < a.size(); i ++ )
    {
        if (a[i] == '1')
        {
            one = i;
        }
        else if (a[i] == '0')
        {
            if (zero == a.size() - 1)zero = i;
        }
    }
    cout << abs((zero - one + 1)) << endl;
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