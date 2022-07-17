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

vector<vector<int>> mp;
vector<vector<int>> pre;
map<int, vector<pair<int, int>>> vec;
int n, m;

void solve()
{
    cin >> n >> m;
    mp.resize(n + 1, vector<int>(m + 1));
    pre.resize(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char a;
            cin >> a;
            if (a == 'G')
                mp[i][j] = 1;
            else
                mp[i][j] = -1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            pre[i][j] = pre[i][j - 1] + mp[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int last = 1;
        for (int j = 1; j <= m;)
        {
            while (true)
            {
                if (j <= m)
                {
                    if (pre[i][j] - pre[i][last - 1] == j - last + 1 || pre[i][j] - pre[i][last - 1] == -(j - last + 1))
                        j++;
                    else
                        break;
                }
                else
                    break;
            }
            vec[i].push_back({last, j - 1});
            last = j;
        }
    }

    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        debug(vec[i]);
        for (auto &p : vec[i])
        {
            debug(p, ans);
            if (p.second - p.first + 1 <= ans)
                continue;
            for (int j = i + 1; j <= min(n, i + p.second - p.first); j++)
            {
                int len = j - i + 1;
                if (p.first + len - 1 > m)
                {
                    break;
                }
                int k = 0;
                while (k < vec[j].size() && p.first > vec[j][k].second)
                    k++;
                if (p.first + len - 1 <= vec[j][k].second)
                    ans = max(len, ans);
                else
                    break;
            }
        }
    }

    cout << ans * ans << endl;
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
'