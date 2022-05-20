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

    if (((a == 0 || b == 1) && k) || k > a + b - 2 ) returnNo;
    cout << "YES" << endl;
    int x1 = 0, x0 = 0, y1 = 0, y0 = 0;
    string x, y;
    if (b)
    {
        x1 ++, y1 ++;
        x += "1", y += "1";
    }
    for (int i = x1; i < b; i ++ ) x += "1";
    for (int i = x0; i < a; i ++ ) x += "0";
    if (k <= a) // 只挪动后面的
    {
        for (int i = y1 + 1; i < b; i ++ ) y += "1";
        for (int i = y0; i < k; i ++ ) y += "0";
        y += "1";
        for (int i = k; i < a; i ++ ) y += "0";
    }
    else
    {
        for (int i = y1; i < a + b - k - 1; i ++ ){y += "1"; y1 ++;}
        y += "0";
        for (int i = y1; i < b - 1; i ++ ){y += "1";}
        for (int i = 0; i < a - 1; i ++ ) y += "0";
        y += "1";
    }
    cout << x << '\n' << y;
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