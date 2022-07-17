#include <bits/stdc++.h>
using namespace std;

//用于比较常见的 输出"YES"和"NO"题目
#define returnNo return void(puts("No"))
#define returnYes return void(puts("Yes"))
//

//用于 debug函数,只会在本地编辑器才显示
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
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
//

//常用头
#define int long long
#define endl '\n'
constexpr int N = 2e5 + 10;

void solve()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    vector<int>s, t;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != a[i + 1]) s.push_back(i);
        if (b[i] != b[i + 1]) t.push_back(i);
    }

    int ans = 0;
    if (s.size() != t.size() || a[0] != b[0] || a[n - 1] != b[n - 1]) ans = -1;
    else
    {
        for (int i = 0; i < s.size(); i ++ )
        {
            ans += abs(s[i] - t[i]);
        }
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