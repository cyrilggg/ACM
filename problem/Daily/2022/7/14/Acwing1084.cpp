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

#define int long long
#define endl '\n'
constexpr int N = 2e5 + 10;
int l, r, P;
vector<vector<vector<int>>>dp;

int mod(int x, int y)
{
    return (x % y + y) % y;
}

void init()
{
    dp.resize(15, vector<vector<int>>(10, vector<int>(111)));
    for (int i = 0; i <= 9; i ++ )
    {
        dp[1][i][i % P] ++;
    }
    for (int i = 2; i < 15; i ++ )
    {
        for (int j = 0; j <= 9; j ++ )
        {
            for (int k = 0; k < P; k ++ )
            {
                for (int x = 0; x <= 9; x ++ )
                    dp[i][j][k] += dp[i - 1][x][mod(k - j, P)];
            }
        }
    }
}

int dpp(int n)
{
    if (!n) return 1;
    vector<int>nums;
    while (n)
    {
        nums.push_back(n % 10);
        n /= 10;
    }
    int res = 0;
    int last = 0;
    for (int i = nums.size() - 1; i >= 0; i -- )
    {
        int x = nums[i];
        for (int j = 0; j < x; j ++ )
        {
            res += dp[i + 1][j][mod(- last, P)];
        }
        last += x;
        if (!i && last % P == 0) res ++;
    }
    return res;
}

void solve()
{
    init();
    cout << dpp(r) - dpp(l - 1) << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin >> _;
    while (cin >> l >> r >> P)
        solve();
}