#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve()
{
   bool flaga = false, flagb = false;
   int n;
   cin >> n;
   vector<int>v(n + 1);
   for (int i = 1; i <= n; i ++ )   cin >> v[i];
   for (int i = 1; i <= n - 2; i += 2 )
   {
      if ((v[i] & 1 && !(v[i + 2] & 1)) || (!(v[i] & 1) && (v[i + 2] & 1))) flaga = 1;
   }
   for (int i = 2; i <= n - 2; i += 2 )
   {
      if ((v[i] & 1 && !(v[i + 2] & 1)) || (!(v[i] & 1) && (v[i + 2] & 1))) flagb = 1;
   }
   if (flaga || flagb) puts("NO");
   else puts("YES");
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