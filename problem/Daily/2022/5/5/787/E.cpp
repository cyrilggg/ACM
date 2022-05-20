#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define returnNo return void(puts("No"))
#define returnYes return void(puts("Yes"))

void solve()
{
    int n, k;
    cin >> n >> k;
    string a;
    cin >> a;
    char s = a[0];
    char nxt = '?';
    for (int i = 0; i < n; i ++ )
    {
        if (a[i] - 'a' > k)
        {
            if (i > 0)nxt = a[i];
            break;
        }
        else
        {
            s = max(s, a[i]);
        }
    }
    //cout << s << endl;
    char minn = s - k >= 'a' ? s - k : 'a';
    char minnn = nxt - (k - s + minn);
    for (int i = 0; i < n; i ++ )
    {
        if (a[i] > s) 
        {
            if (nxt != '?' && a[i] <= nxt)a[i] = min(minnn, a[i]);
        }
        else a[i] = min(a[i], minn);
    }
    cout << a << endl;
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