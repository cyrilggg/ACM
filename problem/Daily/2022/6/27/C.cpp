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
    int n, m, k;
    cin >> n >> k;
    vector<pair<int,int>> a;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        int c = 1;
        while (x % k == 0)
        {
            x /= k;
            c *= k;
        }
        if (a.size() && a.back().first != x) a.push_back({x, c});
        else if (a.size())a.back().second += c;
        else a.push_back({x, c});
    }
    cin >> m;
    vector<pair<int,int>> b;
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        int c = 1;
        while (x % k == 0)
        {
            x /= k;
            c *= k;
        }
        if (b.size() && b.back().first != x) b.push_back({x, c});
        else if (b.size()) b.back().second += c;
        else b.push_back({x, c});
    }
    debug(a, b);
    if (a.size() != b.size()) returnNo;
    for (int i = 0; i < a.size(); i ++ )
        if (a[i] != b[i]) returnNo;
    returnYes;
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