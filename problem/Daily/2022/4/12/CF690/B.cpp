#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'


void solve()
{
   int n;
   string a;
   cin >> n >> a;
   for (int i = 0; i <= 4; i ++ )
   {
      if (a.substr(0, i) + a.substr(n - (4 - i), 4 - i) == "2020") return void(puts("YES"));
   }
   return void(puts("NO"));
}

signed main()
{
   int _ = 1;
   cin >> _;
   while ( _-- )solve();
}