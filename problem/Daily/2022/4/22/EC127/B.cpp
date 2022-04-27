#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define returnNo return void(puts("NO"))
#define returnYes return void(puts("YES"))

void solve()
{
    int n;
    cin >> n;
    vector<int>a(n + 1);
    for (int i = 1; i <= n; i ++ )  cin >> a[i];
    vector<pair<int,int>>pos;
    bool flag = 0;
    for (int i = 1; i < n; i ++ )
    {
        if (a[i + 1] - a[i] > 1)
        {
            if (a[i + 1] - a[i] > 3) returnNo;
            if (a[i + 1] - a[i] == 3) flag = 1;
            pos.push_back({i, i + 1});
        }
    }
    if (pos.size() > 2) returnNo;
    if (pos.size() > 1 && flag) returnNo;
    returnYes;
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