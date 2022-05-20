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

    string a;
    cin >> a;
    
    set<char>S;
    int t;
    cin >> t;
    int ans = 0;
    for (int i = 0; i < t; i ++ )
    {
        char x;
        cin >> x;
        S.insert(x);
    }
    int cnt = 0;
    for (int i = 1; i < n; i ++ )
    {
        if (S.count(a[i]))
        {
            ans = max(ans, cnt + 1);
            cnt = 0;
        }
        else cnt ++;
    }

    cout << ans << endl;
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