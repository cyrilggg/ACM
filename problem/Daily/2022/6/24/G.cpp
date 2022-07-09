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

#define endl '\n'
constexpr int N = 2e5 + 10;

string work(int x)
{
    string a;
    while (x)
    {
        a += to_string(x & 1);
        x >>= 1;
    }
    reverse(a.begin(), a.end());
    return a;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int>v(n);
    for (int i = 0; i < n; i ++ )
    {
        cin >> v[i];
    }
    debug(v);
    int ans = 0;
    for (int i = 0; i < v.size(); i ++ )
    {
        int len = 1;
        while (i + 1 < v.size() &&(2 * v[i + 1] > v[i]))
        {
            i ++;
            len ++;
        }
        ans += (len - k) > 0 ? len - k : 0;
    }
    debug(ans);
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