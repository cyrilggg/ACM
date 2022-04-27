#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve()
{
    string a, b;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    string ans;
    for (int i = 0, j = 0; ;)
    {
        if (i >= a.size())
        {
            ans += b.substr(j);
            break;
        }
        if (j >= b.size()) return void(puts("-1"));
        int cnta = a[i ++ ] - '0';
        int cntb = b[j ++ ] - '0';
        int idx = 10;
        while (j < b.size() && cntb < cnta)
        {
            cntb = cntb + idx * (b[j ++ ] - '0');
            idx *= 10;
        }
        if (cntb < cnta) return void(puts("-1"));
        if (cntb - cnta > 9) return void(puts("-1"));
        ans = ans + to_string(cntb - cnta);
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i ++ )
    {
        if (ans[i] != '0' ||(ans[i] == '0' && i == ans.size() - 1))
        {
            cout << ans.substr(i) << endl;
            break;
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