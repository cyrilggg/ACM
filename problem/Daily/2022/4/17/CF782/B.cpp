#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve()
{
    int n, k;
    cin >> n >> k;
    string a;
    cin >> a;
    vector<int>v;
    vector<int>ans(n);
    int cnt = 0;
    for (int i = 0; i < n; i ++ )
    {
        if (a[i] == '0')
        {
            v.push_back(i);
            cnt ++;
        }
    }
}

signed main()
{
   int _ = 1;
   cin >> _;
   while (_--)
      solve();
}