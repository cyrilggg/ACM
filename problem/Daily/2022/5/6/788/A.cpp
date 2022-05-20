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
    vector<int>v(n);
    for (int i = 0; i < n; i ++ )
    {
        cin >> v[i];
    }
    for (int i = 0, j = n - 1; i < j; j --)
    {
        while (i < j && v[i] < 0) i ++;
        if (v[j] < 0 && v[i] > 0)
        {
            v[j] = -v[j];
            v[i] = -v[i];
            i ++;
        }
    }
    if (is_sorted(v.begin(), v.end()))returnYes;
    else returnNo;
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