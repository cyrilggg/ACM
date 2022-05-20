#include <bits/stdc++.h>
using namespace std;
#define int long long
//#define endl '\n'
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

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> v(n + 1);
    vector<int>s(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i].first;
        v[i].second = i;
    }
    for (int i = 1; i <= n; i ++ )
    {
        s[i] = v[i].first;
    }
    sort(v.begin(), v.end(), [&](pair<int, int> a, pair<int, int> b)
         { return a.first + a.second < b.first + b.second; });
    map<int, int> vis;
    for (int i = 1; i <= n - k; i++)
    {
        vis[v[i].second] = 1;
        debug(v[i]);
    }
    int t = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        debug(i, vis[i], t);
        if (vis[i])
            ans += s[i] + t;
        else
            t++;
    }
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