#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define returnNo return void(puts("No"))
#define returnYes return void(puts("Yes"))

template<class T>
T qmi(T a, T k)  // ¿ìËÙÃÝÄ£°å
{
    T res = 1;
    while (k)
    {
        if (k & 1) res = 1ll * res * a;
        a = 1ll * a * a;
        k >>= 1;
    }
    return res;
}

void solve()
{
    string s, t;
    cin >> s >> t;
    if (count(t.begin(), t.end(), 'a') == 1 && t.size() == 1)
    {
        cout << 1 << endl;
        return;
    }
    else if (count(t.begin(), t.end(), 'a') >= 1)
    {
        cout << -1 << endl;
        return;
    }
    int ans = 0;
    if (count(t.begin(), t.end(), 'a') == 0)
    {
        cout << qmi(2ll, (long long) s.size()) << endl;
    }
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