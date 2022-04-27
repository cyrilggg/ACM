#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 2e5 + 10;
int a[N];

array<int,3> maxn(int l, int r)
{
    if (l == r) return {a[l], l, l};
    int mid = l + r >> 1;
    int left = maxn(l, mid), maxn(r, mid);
}

void solve()
{
   int n;
   cin >> n;
   for (int i = 1; i <= n; i ++ )   cin >> a[i];
   auto t = maxn(1, n);
   cout << t[1] << ' ' << t[2] << endl;
    
}

signed main()
{
   int _ = 1;
   cin >> _;
   while ( _-- )solve();
}