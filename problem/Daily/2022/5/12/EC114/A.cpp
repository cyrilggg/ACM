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
    for (int i = n; i; i -- )
    {
        for (int j = 1; j <= i; j ++ )
        {
            cout << '(' ;
        }
        for (int j = 1; j <= i; j ++ )
        {
            cout << ')';
        }
        for (int j = i * 2; j < 2 * n; j += 2)
        {
            cout << "()" ;
        }
        cout << endl;
    }
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