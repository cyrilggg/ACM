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
    int n;
    cin >> n;
    vector<vector<int>> v(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char x;
            cin >> x;
            v[i][j] = x - '0';
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // if (v[i][j] == 0)
            //     continue;

            double mid = (n + 1) / 2;
            double diffy = abs(i - mid), diffx = abs(j - mid);
            if (i > mid && j > mid)
            {
                int cnt = (v[i][j] == 1) + (v[mid + diffx][mid - diffy] == 1) + (v[mid - diffy][mid - diffx] == 1) + (v[mid - diffx][mid + diffy] == 1);
                if (cnt > 2)
                ans += 4 - cnt;
                else ans += cnt;
                debug(i, j, cnt, mid, ans);
            } //第四象限
            // if (i > mid && j < mid)
            // {
            //     int cnt = 1 + (v[mid - diffx][mid - diffy] == 1) + (v[mid - diffy][mid + diffx] == 1) + (v[mid + diffx][j + diffy] == 1);
            //     if (cnt > 2)
            //     ans += 4 - cnt;
            //     else ans += cnt;
            //     v[mid - diffx][mid - diffy] = v[mid - diffy][mid + diffx] = v[mid + diffx][j + diffy] = 0;
            // } //第三象限
            // if (i < mid && j < mid)
            // {
            //     int cnt = 1 + (v[mid + diffy][j] == 1) + (v[mid + diffy][mid + diffx] == 1) + (v[mid][j + diffx] == 1);
            //     if (cnt > 2)
            //     ans += 4 - cnt;
            //     else ans += cnt;
            //     v[mid + diffy][j] = v[mid + diffy][mid + diffx] = v[mid][j + diffx] = 0;
            // } //第二象限
            // if (i < mid && j > mid)
            // {
            //     int cnt = 1 + (v[mid + diffy][j] == 1) + (v[mid + diffy][mid - diffx] == 1) + (v[mid][j - diffx] == 1);
            //     if (cnt > 2)
            //     ans += 4 - cnt;
            //     else ans += cnt;
            //     v[mid + diffy][j] = v[mid + diffy][mid - diffx] = v[mid][j - diffx] = 0;

            // } //第一象限
            if (i == mid && n & 1)
            {
                if (j == mid) continue;
                int cnt = (v[mid][mid + diffx] == 1) + (v[mid][mid - diffx] == 1) + (v[mid - diffx][mid] == 1) + (v[mid + diffx][mid] == 1);
                if (cnt > 2)
                ans += 4 - cnt;
                else ans += cnt;
                v[mid][mid + diffx] = v[mid][mid - diffx] = v[mid - diffx][mid] = v[mid + diffx][mid] = 0;
                debug(i, j, cnt);
            }
            // else if (j == mid)
            // {
            //     int cnt = (v[mid][mid + diffy] == 1) + (v[mid][mid - diffy] == 1) + (v[mid - diffy][mid] == 1) + (v[mid + diffy][mid] == 1);
            //     if (cnt > 2)
            //     ans += 4 - cnt;
            //     else ans += cnt;
            //     v[mid][mid + diffy] = v[mid][mid - diffy] = v[mid - diffy][mid] = v[mid + diffy][mid] = 0;
            // }
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