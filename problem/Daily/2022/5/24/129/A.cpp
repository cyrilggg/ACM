#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define returnNo return void(puts("No"))
#define returnYes return void(puts("Yes"))

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '['; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << ']'; }
 
void debug_out() { cerr << endl; }
template<typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << ' ' << H; debug_out(T...); }
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 
#endif

void solve()
{
    int n;
    int maxa = -1;
    cin >> n;
    for (int i = 1; i <= n; i ++ )
    {
        int x;
        cin >> x;
        maxa = max(maxa, x);
    }
    int m;
    int maxb = -1;
    cin >> m;
    for (int i = 1; i <= m; i ++ )
    {
        int x;
        cin >> x;
        maxb = max(maxb, x);
    }
    if (maxa == maxb)
    {
        cout << "Alice"<< endl << "Bob" << endl;
    }
    else if (maxa < maxb)
    {
        cout << "Bob" << endl << "Bob" << endl;
    }
    else
    {
        cout << "Alice" << endl << "Alice" << endl;
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