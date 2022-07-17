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

void solve(int _)
{
    int x, y;
    cin >> x >> y;
    int cnta = 0, cntb = 0, cntdiff = 0;
    vector<int> a, b;
    map<int, int> A, B;
    for (int i = 1; i <= 62; i++)
    {
        if (((x >> (i - 1)) & 1) == 1)
        {
            A[i] = 1;
        }
        if (((y >> (i - 1)) & 1) == 1)
        {
            B[i] = 1;
        }
    }

    int ans = 0;
    for (int i = 1; i <= 62; i += 2)
    {
        if (A[i])
            a.push_back(i);
        if (B[i])
            b.push_back(i);
    }
    if (a.size() != b.size())
    {
        cout << "Case " << _ << ": " << -1 << endl;
        return;
    }
    for (int i = 0; i < a.size(); i ++ )
    {
        ans += abs(a[i] - b[i]) / 2;
    }
    a.clear();
    b.clear();
    for (int i = 2; i <= 62; i += 2)
    {
        if (A[i])
            a.push_back(i);
        if (B[i])
            b.push_back(i);
    }
    if (a.size() != b.size())
    {
        cout << "Case " << _ << ": " << -1 << endl;
        return;
    }
    for (int i = 0; i < a.size(); i ++ )
    {
        ans += abs(a[i] - b[i]) / 2;
    }

    cout << "Case " << _ << ": " << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int _ = 1;
    cin >> _;
    for (int i = 1; i <= _; i++)
        solve(i);
}