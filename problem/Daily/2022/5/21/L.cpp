#include <bits/stdc++.h>
using namespace std;
//#define int long long
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

#define lowbit(i) (i & (-i))
template <typename T>
struct Fenwick
{
    vector<T> fenwick;
    int n;
    
    Fenwick(int _n) : n(_n)
    {
        fenwick.resize(n + 1);
    }

    void modify(int x, T val)
    {
        while (x <= n)
        {
            fenwick[x] += val;
            x += lowbit(x);
        }
    }

    T get(int x)
    {
        T cnt{};
        while (x)
        {
            cnt += fenwick[x];
            x -= lowbit(x);
        }
        return cnt;
    }
};

void solve()
{
    int n;
    int l, r;
    cin >> n >> l >> r;
    vector<int>v(n + 1);
    
    for (int i = 1; i <= n; i ++ )
    {
        cin >> v[i];
        if (v[i] > r) v[i] = 1;
        else if (v[i] < l) v[i] = -1;   
        else v[i] = 0;
    }
    
    int ans = 0;
    int k = 0;
    for (int i = 1; i <= n; i ++ )
    {
        if (v[i] == 0)
        {
            k ++;
        }
        else
        {
            ans -= (1 + k) * k / 2;
            k = 0;
        }
        v[i] += v[i - 1];
    }
    ans -= (1 + k) * k / 2;
    Fenwick<int> S(2e5 + 10);
    S.modify(1e5, 1);
    for (int i = 1; i <= n; i ++ )
    {
        ans += S.get(v[i] + 1e5);
        S.modify(v[i] + 1e5, 1);
    }
    
    cout << ans << endl;
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