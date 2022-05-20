#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define returnNo return void(puts("No"))
#define returnYes return void(puts("Yes"))
const int N = 1e5 + 10;
void solve()
{
    int a, b, k;
    cin >> a >> b >> k;
    int tmp = k;
    int cnto = k / 3, cntz = k / 3 * 2;
    tmp %= 3;
    cnto += tmp, cntz += tmp;
    //cout << cnto << ' ' << cntz << endl;
    if (cnto + 1 > b || cntz > a) returnNo;
    int x1 = 1, x0 = 0, y1 = 1, y0 = 0;
    cout << "Yes" << endl;
    string x, y;
    x += "1", y += "1";
    for (int i = 0; i < k / 3; i ++ )
    {
        x += "100";
        y += "001";
        x1 += 1, x0 += 2, y1 += 1, y0 += 2;
    }
    for (int i = 0; i < tmp; i ++ )
    {
        x += "10";
        y += "01";
        x1 += 1, x0 += 1, y1 += 1, y0 += 1;
    }
    for (int i = x1 + 1; i <= b; i ++ )
    {
        x += "1";
        y += "1";
    }
    for (int i = x0 + 1; i <= a; i ++ )
    {
        x += "0";
        y += "0";
    }
    cout << x << endl << y << endl;
}

signed main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   int _ = 1;
   //cin >> _;
   while (_--)
      solve();
}