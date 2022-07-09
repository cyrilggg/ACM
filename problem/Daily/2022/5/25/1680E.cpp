#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define returnNo return void(puts("No"))
#define returnYes return void(puts("Yes"))

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p)
{
    return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
    os << '[';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << ']';
}

void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    debug_out(T...);
}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif
constexpr int N = 2e5 + 10;
void solve()
{
    int n;
    cin >> n;
    vector<vector<char>> g(3, vector<char>(n + 1));
    vector<vector<int>> f(n + 1, vector<int>(3, 1e12));
    for (int i = 1; i <= 2; i++)
        for (int j = 1; j <= n; j++)
            cin >> g[i][j];
    

    while (n >= 1 && g[1][n] == '.' && g[2][n] == '.') n--;
    
    f[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (g[1][i] != '*' && g[2][i] != '*')
        {
            f[i][0] = f[i - 1][0];
            f[i][1] = min({f[i - 1][1] + 1, f[i - 1][2] + 2});
            f[i][2] = min({f[i - 1][1] + 2, f[i - 1][2] + 1});
        }
        else if (g[1][i] == '*' && g[2][i] != '*')
        {
            f[i][1] = min({f[i - 1][0], f[i - 1][1] + 1, f[i - 1][2] + 2});
            f[i][2] = min({f[i - 1][0] + 1, f[i - 1][1] + 2, f[i - 1][2] + 2});
        }
        else if (g[1][i] != '*' && g[2][i] == '*')
        {
            f[i][1] = min({f[i - 1][0] + 1, f[i - 1][1] + 2, f[i - 1][2] + 2});
            f[i][2] = min({f[i - 1][0], f[i - 1][1] + 2, f[i - 1][2] + 1});
        }
        else
        {
            f[i][1] = min({f[i - 1][0] + 1, f[i - 1][1] + 2, f[i - 1][2] + 2});
            f[i][2] = min({f[i - 1][0] + 1, f[i - 1][1] + 2, f[i - 1][2] + 2});
        }
    }
    cout << min(f[n][1], f[n][2]) << '\n';
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