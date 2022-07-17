#include <bits/stdc++.h>
using namespace std;

#define returnNo return void(puts("No"))
#define returnYes return void(puts("Yes"))

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '['; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << ']'; }
 
void debug_out() { cerr << endl; }
template<typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << ' ' << H; debug_out(T...); }
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 
#endif

#define int long long
#define endl '\n'
constexpr int N = 15;
int l, r;
int f[N][N];

void init()
{
    for (int i = 0; i < N; i ++ ) f[1][i] = 1;

    for (int i = 2; i < N; i ++ )
        for (int j = 0; j <= 9; j ++ )
            for (int k = j; k <= 9; k ++ )
                f[i][j] += f[i - 1][k];
}
int dp(int n)
{
    if (!n) return 1;
    vector<int>nums;
    while (n) nums.push_back(n % 10), n /= 10;

    int res = 0;
    int last = 0;
    for (int i = nums.size() - 1; i >= 0; i -- )
    {
        int x = nums[i];
        for (int j = last; j < x; j ++ )
            res += f[i + 1][j];
        if (last > x) break;
        last = x;
        if (!x) res ++;
    } 
    return res;
} 

void solve()
{
    cout << dp(r) - dp(l - 1) << endl;
}

signed main()
{
    init();
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   while(cin >> l >> r)
      solve();
}