#include <bits/stdc++.h>
using namespace std;

//用于比较常见的 输出"YES"和"NO"题目
#define returnNo return void(puts("No"))
#define returnYes return void(puts("Yes"))
//

//用于 debug函数,只会在本地编辑器才显示
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '['; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << ']'; }
 
void debug_out() { cerr << endl; }
template<typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << ' ' << H; debug_out(T...); }
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 
#endif
//

//常用头
#define int long long
#define endl '\n'
constexpr int N = 2e5 + 10;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>>v(n + 1, vector<int>(n + 1)), dp(n + 1, vector<int>(n + 1));
    
    for (int i = 1; i <= n; i ++ )
    {
        for (int j = 1; j <= i; j ++ )
        {
            cin >> v[i][j];
        }
    }
    int ans = -1e12;
    for (int i = 1; i <= n; i ++ )
    {
        for (int j = 1; j <= i; j ++ )
        {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + v[i][j];
            if (i == n)ans = max(dp[i][j], ans);
        }
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