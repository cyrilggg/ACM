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
    vector<int>v(n + 1);
    for (int i = 1; i <= n; i ++ )
    {
        cin >> v[i];
        if (v[i] == i) v[i] = 1;
        else v[i] = 0;
    }
    int cnt = 0;
    for (int i = 1; i <= n;)
    {
        while (i <= n && v[i] == 1) i ++;
        if (!v[i])
        {
            cnt ++;
            while (i <= n && v[i] == 0) i ++ ;
        }
    }
    cout << min(cnt, 2ll) << endl;
    
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