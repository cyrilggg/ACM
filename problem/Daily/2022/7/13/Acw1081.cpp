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

struct Conbi
{
    typedef long long ll;
    const static int p = 1000000007;
    vector<int> fac, inv;
    int qpow(int x, int y)
    {
        if (y == 0)
            return 1;
        int res = 1;
        for (; y > 0; y >>= 1, x = (ll)x * x % p)
            if (y & 1)
                res = (ll)res * x % p;
        return res;
    }
    Conbi(int n) : fac(n + 1), inv(n + 1)
    {
        fac[0] = 1;
        for (int i = 1; i <= n; ++i)
            fac[i] = (ll)fac[i - 1] * i % p;
        inv[n] = qpow(fac[n], p - 2);
        for (int i = n - 1; i >= 0; --i)
            inv[i] = (ll)inv[i + 1] * (i + 1) % p;
    }
    int operator()(int x, int y)
    {
        if (y < 0 || y > x)
            return 0;
        return (ll)fac[x] * inv[y] % p * inv[x - y] % p;
    }
} C(50);

int l, r, k, b;

int dp(int n)
{
    if (!n)
        return 0;

    vector<int> nums;
    while (n)
        nums.push_back(n % b), n /= b;

    int res = 0;
    int last = 0;

    for (int i = nums.size() - 1; i >= 0; i--)
    {
        int x = nums[i];
        if (x > 0)
        {
            res += C(i, k - last);

            if (x > 1)
            {
                if (k - last - 1 >= 0)
                    res += C(i, k - last - 1);
                break;
            }
            else
            {
                last++;
                if (last > k)
                    break;
            }
        }

        if (i == 0 && last == k)
            res++;
    }
    return res;
}

void solve()
{
    cin >> l >> r >> k >> b;
    cout << dp(r) - dp(l - 1) << endl;
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
