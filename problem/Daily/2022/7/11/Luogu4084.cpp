#include <bits/stdc++.h>
using namespace std;

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

#define endl '\n'
constexpr int N = 2e5 + 10;

constexpr int P = 1e9 + 7;
using i64 = long long;
int norm(int x)
{
    if (x < 0)
    {
        x += P;
    }
    if (x >= P)
    {
        x -= P;
    }
    return x;
}

template <class T>
T power(T a, i64 b)
{
    T res = 1;
    for (; b; b /= 2, a *= a)
    {
        if (b % 2)
        {
            res *= a;
        }
    }
    return res;
}

struct Z
{
    int x;
    Z(int x = 0) : x(norm(x)) {}
    Z(i64 x) : x(norm((int)(x % P))) {}
    int val() const
    {
        return x;
    }
    Z operator-() const
    {
        return Z(norm(P - x));
    }
    Z inv() const
    {
        assert(x != 0);
        return power(*this, P - 2);
    }
    Z &operator*=(const Z &rhs)
    {
        x = i64(x) * rhs.x % P;
        return *this;
    }
    Z &operator+=(const Z &rhs)
    {
        x = norm(x + rhs.x);
        return *this;
    }
    Z &operator-=(const Z &rhs)
    {
        x = norm(x - rhs.x);
        return *this;
    }
    Z &operator/=(const Z &rhs)
    {
        return *this *= rhs.inv();
    }
    friend Z operator*(const Z &lhs, const Z &rhs)
    {
        Z res = lhs;
        res *= rhs;
        return res;
    }
    friend Z operator+(const Z &lhs, const Z &rhs)
    {
        Z res = lhs;
        res += rhs;
        return res;
    }
    friend Z operator-(const Z &lhs, const Z &rhs)
    {
        Z res = lhs;
        res -= rhs;
        return res;
    }
    friend Z operator/(const Z &lhs, const Z &rhs)
    {
        Z res = lhs;
        res /= rhs;
        return res;
    }
};

vector<vector<Z>> dp;
vector<int> e[N];
void dfs(int u, int fa)
{

    for (int i = 0; i <= 2; i++)
    {
        if (dp[u][i].val())
        {
            for (int j = 0; j < i; j ++ )
            {
                dp[u][j] = 0;
            }
            break;
        }
        dp[u][i] = 1;
    }
    for (int i = 0; i < e[u].size(); i++)
    {
        int j = e[u][i];
        if (j == fa)
            continue;
        dfs(j, u);
        dp[u][0] *= (dp[j][1] + dp[j][2]);
        dp[u][1] *= dp[j][0] + dp[j][2];
        dp[u][2] *= dp[j][1] + dp[j][0];
    }
}
void solve()
{
    i64 n, k;
    cin >> n >> k;
    dp.resize(n + 1, vector<Z>(3));

    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    for (int i = 1; i <= k; i++)
    {
        int a, b;
        cin >> a >> b;
        b--;
        dp[a][b] = 1;
    }
    dfs(1, 1);
    dp[1][0] += dp[1][1] + dp[1][2];
    cout << dp[1][0].val() << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--)
        solve();
}