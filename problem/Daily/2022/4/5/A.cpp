#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

string s, t;

bool dfs(int x, string tmp, bool flag)
{
   // cout << x << ' ' << tmp << endl;
    if (tmp == t) return true;
    bool flag = false;
    if (x + 1 < s.size() && s[x + 1] == t[tmp.size()])
        flag |= dfs(x + 1, tmp + s[x + 1]);
    if (flag == 1) return true;
    if (x - 1 > 0 && s[x - 1] == t[tmp.size()])
        flag |= dfs(x - 1, tmp + s[x - 1]);
    return flag;
}

void solve()
{
    cin >> s >> t;
    for (int i = 0; i < s.size(); i ++ )
    {
        if (s[i] == t[0])
        {
            if (dfs(i, s.substr(i, 1), 1)) return void(puts("YES"));
        }
    }
    return void(puts("NO"));
}

signed main()
{
   int _ = 1;
   cin >> _;
   while ( _-- )solve();
}