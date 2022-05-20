#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
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

constexpr int N = 50010, M = 200010, S = 1000010;
int n, m, len;
int w[N], ans[N];
struct Query
{
    int id, l, r;
}q[M];
int cnt[S];

inline int get(int x)
{
    return x / len;
}

bool cmp(const Query& a, const Query& b)
{
    int i = get(a.l), j = get(b.l);
    if (i != j) return i < j;
    return a.r < b.r;
}

void add(int x, int &res )
{
    if (!cnt[x]) res ++;
    cnt[x] ++;
}

void del(int x, int &x)
{
    cnt[x] --;
    if (!cnt[x]) res --;
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++ i )
    {
        cin >> w[i];
    }
    len = sqrt((double)n * n / m);
    cin >> m;
    for (int i = 0; i < m; i ++ )
    {
        int l, r;
        cin >> l >> r;
        q[i] = {i, l, r};
    }
    sort(q, q + m, cmp);
    for (int k = 0, i = 0, j = 1, res = 0; k < m; ++ k )
    {
        int id = q[i].id, l = q[i].l, r = q[i].r;
        while (i < r) add(w[++ i], res);
        while (i > r) del(w[i --], res);
        while (j < l) del(w[j ++], res);
        while (j > l) add(w[-- j], res);
        ans[id] = res;
    }

}   

signed main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   int _ = 1;
   //cin >> _;
   while (_--)
      solve();
}