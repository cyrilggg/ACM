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

void solve()
{
    int n, k;
    cin >> n >> k;
    int ans = 0;
    vector<int> v(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        pre[i] = pre[i - 1] + v[i];
    }
    
    int idx = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i ++ )
    {
        int sum = pre[i - 1] - (i - 1) * k;
        int idx = 1;
        for (int j = i; j <= min(i + 32, n); j ++ )
        {
            sum += v[j] >> idx;
            idx ++;
        }
        ans = max(sum, ans);
    }
    ans = max(pre[n] - n * k, ans);
    cout << ans << endl;
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