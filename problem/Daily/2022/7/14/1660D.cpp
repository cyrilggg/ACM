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
    vector<int> v(n + 1);
    map<int, vector<int>> mp;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        if (v[i] < 0)
        {
            mp[-1].push_back(i);
        }
        else if (v[i] == 0)
        {
            mp[0].push_back(i);
        }
    }
    if (mp[0].size() == n)
    {
        cout << 1 << endl;
    }
    int ans = 1;
    int last = 1;
    for (int i = 1; i <= n; i ++ )
    {
        if (v[i] == 0)
        {
            if (last < i - 1)
            {
                ans = max(check(v, last, i - 1), ans);
            }
            last = i + 1;
        }
    }
    
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