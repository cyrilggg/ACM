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
constexpr int N = 1e5 + 10;

int count (vector<int>&v)
{
    int pre = 0, now = 0, ans = 0;

    sort(v.begin(), v.end());
    for (auto &vv : v){
        ans += now * vv - pre;
        now ++, pre += vv;
    }
    return ans;
}
void solve()
{
   int n, m;
   cin >> n >> m;
   map<int,vector<int>>c, r;
   for (int i = 1; i <= n; i ++ )
   {
       for (int j = 1; j <= m; j ++ )
       {
            int x;
            cin >> x;
            c[x].push_back(i);
            r[x].push_back(j);
       }
   }
   int ans = 0;
   for (int i = 1; i <= N; i ++ )
   {
       ans += count(c[i]) + count(r[i]);
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