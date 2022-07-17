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
   string a;
   int n;
   cin >> a >> n;
   vector<int>e;
   for (int i = 0; i < a.size(); i ++ )
   {
       if (a[i] == 'E') e.push_back(i);
   }
   int ans = 0;
   for (int i = 0; i < e.size(); i ++ )
   {
       int l = e[i] - n + 1;
       int r = e[i] + n - 1;
       
       debug(e[i], l, r);
       if (l < 0)
       {
           l += a.size();
       }
       if (r >= a.size())
       {
           r -= a.size();
       }
       debug(e[i], l, r);
       debug(e);
       if (l < r)
       {
           int lb = upper_bound(e.begin(), e.end(), l + 1) - e.begin();
           int rb = (lower_bound(e.begin(), e.end(), r - 1) - 1 - e.begin());
           ans += 2 * n;
           ans -= rb - lb + 1;
           debug(l, r, lb, rb);
        }
       else if (l > r)
       {
           int lb = lower_bound(e.begin(), e.end(), r + 1) - e.begin();
           int rb = upper_bound(e.begin(), e.end(), l - 1) - e.begin();
           ans += 2 * n;
           ans -= e.size() + e.size() - rb + 1 + lb;
           debug(l, r, lb, rb);
       }
       else
       {
           ans ++;
       }
       debug(ans);
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