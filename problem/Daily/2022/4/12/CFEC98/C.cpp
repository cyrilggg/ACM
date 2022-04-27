#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve()
{
    int cnt = 0;
    int a = 0, b = 0;
    string s;
    cin >> s;
    bool finda = false, findb = false;
    for (int i = 0; i < s.size(); i ++ )
    {
        if (s[i] == ')')
        {
            if (finda && a)
            {
                a --;
                cnt ++;
            }
        }
        if (s[i] == ']')
        {
            if (findb && b)
            {
                b --;
                cnt ++;
            }
        }
        if (s[i] == '(')
        {
            finda = 1;
            a ++;
        }
        if (s[i] == '[')
        {
            findb = 1;
            b ++;
        }
    }
    cout << cnt << endl;
}

signed main()
{
   int _ = 1;
   cin >> _;
   while (_--)
      solve();
}