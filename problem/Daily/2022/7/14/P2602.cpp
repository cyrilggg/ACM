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

int l, r;
int base[14];
int f[14][10];
int g[14][10];
void init()
{
    base[0] = 1;
    for (int i = 1; i <= 13; i++)
        base[i] = 10 * base[i - 1];

    for (int i = 0; i <= 9; i++)
        f[1][i] = 1;

    for (int i = 1; i <= 13; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            f[i][j] = 10 * f[i - 1][j] + base[i - 1];
        }
    }

    for (int i = 1; i <= 9; i++)
        g[1][i] = 1;
    for (int i = 2; i <= 13; i++)
    {
        g[i][0] = g[i - 1][0] + f[i - 1][0] * 9;
        for (int j = 1; j <= 9; j++)
            g[i][j] = g[i - 1][j] + f[i - 1][j] * 9 + base[i - 1];
    }
}

vector<int> dp(int n)
{
    vector<int> ans(10, 0);
    if (!n)
        return ans;

    vector<int> nums;
    while (n)
        nums.push_back(n % 10), n /= 10;

    vector<int> last(10, 0); 

    for (int i = 0; i <= 9; i++)
        ans[i] = g[nums.size() - 1][i];
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        int x = nums[i];
        for (int j = i == nums.size() - 1; j < x; j++)
        { 
            for (int k = 0; k <= 9; k++)
                ans[k] += last[k] * base[i];
            ans[j] += base[i];
            for (int k = 0; k <= 9; k++)
                ans[k] += f[i][k];
        }
        last[x]++;

        if (!i)
            for (int k = 0; k <= 9; k++)
                ans[k] += last[k];
    }
    return ans;
}
void solve()
{
    init();
    cin >> l >> r;
    auto rr = dp(r);
    auto ll = dp(l - 1);
    debug(rr);
    debug(ll);
    for (int i = 0; i <= 9; i++)
        cout << rr[i] - ll[i] << ' ';
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