
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

int bs(vector<pair<int,int>> &cur, int x)
{
    int l = 0, r = cur.size() - 1;
    while (l < r)
    {
        //debug(l, r);
        int mid = l + r >> 1;
        if (cur[mid].first >= x) 
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
        //debug(mid, cur[mid].first, l, r);
    }
    if (cur[l].first >= x) return l;
    else return l - 1;
}

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    string S;
    cin >> S;

    vector<pair<int, int>> adds;
    vector<int> queries;

    vector<pair<int, int>> cur;
    int last = n;
    cur.push_back({n, 0});
    for (int i = 1; i <= m; i++)
    {
        int l, r;
        cin >> l >> r;
        adds.push_back({l, r});
        last += r - l + 1;
        cur.push_back({last, i});
    }

    for (int i = 1; i <= q; i++)
    {
        int x;
        cin >> x;
        int idx = bs(cur, x);
        int xx = x;
        while (idx > 0)
        {
            debug(adds[idx - 1], cur[idx - 1]);
            xx = adds[idx - 1].first + x - cur[idx - 1].first - 1;
            x = xx;
            debug(idx, xx);
            idx =bs(cur, xx);
            debug(idx, xx);
            if (idx < 0) break;
        }
        cout << S[xx - 1] << endl;
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