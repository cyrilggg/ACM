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
constexpr int N = 110;

int n, m;
vector<pair<int,int>>e[N];
int dp[N][N];
void dfs(int u, int fa)
{

    for (auto &v : e[u])
    {
        int j = v.first, w = v.second;
        if (j == fa) continue;
        dfs(j, u);
        for (int i = m; i; i -- )
        {
            for (int k = 0; k < i; k ++ )
            {
                if (i - k - 1 >= 0) 
                {
                    dp[u][i] = max(dp[u][i], dp[u][i - k - 1] + dp[j][k] + w); 
                    debug(u, i, dp[u][i]);
                }
            }
        }
    }
}

void solve()
{

    cin >> n >> m;
    for (int i = 1; i < n; i ++ )
    {
        int a, b, c;
        cin >> a >> b >> c;
        e[a].push_back({b, c});
        e[b].push_back({a, c});
    }
    dfs(1, 1);
    cout << dp[1][m] << endl;
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