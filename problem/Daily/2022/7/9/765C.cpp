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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int>d(n + 2), a(n + 1);
    for (int i = 1; i <= n; i ++ )   cin >> d[i];
    for (int i = 1; i <= n; i ++ )   cin >> a[i];
    d[++ n] = m;
    vector<vector<int>>dp (n + 1, vector<int>(n + 1, 1e12));
    dp[1][1] = 0;
    
    for (int i = 2; i <= n; i ++ )
        for (int j = 1; j <= i; j ++ )
        {
            for (int l = 1; l < i; l ++ ){
                dp[i][j] = min(dp[i][j], dp[l][j - 1] + (d[i] - d[l]) * a[l]);
                debug(i, j, dp[i][j]);
            }
        }
    int sum = 1e9;
    for (int i = 0; i <= k; i ++ ){
        sum = min(sum, dp[n][n - i]);
    }
    cout << sum << endl;
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