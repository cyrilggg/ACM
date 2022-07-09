#include <bits/stdc++.h>
using namespace std;

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

#define int long long
#define endl '\n'
constexpr int N = 2e5 + 10;

void solve()
{
    set<int>v;
    for (int i = 0; i <= 120; i ++ )
    {
        for (int j = 0; j <= 120; j ++ )
        {
            for (int k = 0; k <= 120; k ++ )
            {
                for (int s = 0; s <= 120; s ++ )
                {
                    v.insert(i * 5 + 7 * j + 11 * k + 13 * s);
                }
            }
        }
    }
    for (int i = 1; i <= 3600; i ++ )
    {
        if (!v.count(i))cout << i << endl;
    }
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