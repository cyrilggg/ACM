#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve()
{
    string a;
    cin >> a;
    if (a.size() & 1) 
        return void(puts("NO"));
    //cout << a.substr(0, a.size() / 2) <<' '<< a.substr(a.size() / 2, a.size() / 2) << endl;
    if (a.substr(0, a.size() / 2) == a.substr(a.size() / 2, a.size() / 2)) return void(puts("YES"));
    return void(puts("NO"));
}

signed main()
{
   int _ = 1;
   cin >> _;
   while (_--)
      solve();
}