#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define returnNo return void(puts("No"))
#define returnYes return void(puts("Yes"))
void solve()
{
    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;
    vector<int>v;
    for (int i = 0, j = 0; i < n && j < m; j ++, i ++ )
    {
        while (i < n && s[i] != t[j])
        {
            i ++;
        }
        if (s[i] == t[j])v.push_back(i);
    }
    int ans = -1;
    v.pop_back();
    for (int i = n - 1, j = m - 1; i >= 0; i --, j --)
    {
        while (i >= 0 && s[i] != t[j])
        {
            i --;
        }
        if (s[i] == t[j])
        {
            ans = max(i - v.back(), ans);
            v.pop_back();
        }
    }
    cout << ans << endl;
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