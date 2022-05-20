#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define returnNo return void(puts("No"))
#define returnYes return void(puts("Yes"))

int lcm(int a, int b)
{
    int gcd = __gcd(a, b);
    return a * b / gcd;
}
void solve()
{
   int n;
   cin >> n;
   int minn = 1e12;
    int a, b;
   for (int i = 1; i <= n / 2; i ++ )
   {
       if (lcm(i, n - i) < minn)
       {
           a = i;
           b = n - i;
           minn = lcm(i, n - i);
       }
   }
   cout << a << ' ' << b << endl;
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