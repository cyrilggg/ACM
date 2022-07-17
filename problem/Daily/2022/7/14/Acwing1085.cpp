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
int l, r;
vector<vector<int>> dp;

int mod(int x, int y)
{
    return (x % y + y) % y;
}

void init()
{
    dp.clear();
    dp.resize(15, vector<int>(10));
    for (int i = 1; i <= 14; i++)
        if (i != 4)
            dp[1][i] = 1;
    for (int i = 2; i <= 14; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            if (j == 4)
                continue;
            for (int k = 0; k <= 9; k++)
            {
                if (k == 4 || ((j == 6) && (k == 2)))
                    continue;
                dp[i][j] += dp[i - 1][j];
            }
        }
    }
}

int dpp(int n)
{
    if (!n)
        return 1;
    vector<int> nums;
    while (n)
    {
        nums.push_back(n % 10);
        n /= 10;
    }
    int res = 0;
    int last = 0;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        int x = nums[i];
        for (int j = 0; j < x; j++)
        {
            if (j == 4 || ((last == 6) && (j == 2)))
                continue;
            res += dp[i + 1][j];
        }
        if (x == 4 || (last == 6 && x == 2)) break;
        last = x;
        if (!i)
            res++;
    }
    return res;
}

void solve()
{
    cout << dpp(r) - dpp(l - 1) << endl;
}

signed main()
{
    
    init();
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin >> _;
    while (cin >> l >> r && l + r)
        solve();
}