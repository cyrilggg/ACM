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
    int a1 = -1e12, a2 = -1e12, a3 = -1e12 , a4 = -1e12;
    int n, m;
    cin >> n >> m;
    vector<vector<char>>mp(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; i ++ )
    {
        for (int j = 1; j <= m ; j ++ )
        {
            cin >> mp[i][j];
            if (mp[i][j] == 'B')
            {
                a1 = max(a1, -i + j);
                a2 = max(a2, -i - j);
                a3 = max(a3, i - j);
                a4 = max(a4, i + j);
            }
        }
    }
    pair<int,int>an = {1, 1};
    int ans = 1e12;
    for (int i = 1; i <= n; i ++ )
    {
        for (int j = 1; j <= m; j ++ )
        {
            int t = max({a1 + i - j, a2 + i + j, a3 - i + j, a4 - i - j});
            if (t < ans)
            {
                an = {i, j};
                ans = t;
            }
        }
    }
    cout << an.first << ' ' << an.second << endl;

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