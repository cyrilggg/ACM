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

void solve()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int cnta = 0, cntb = 0;
    for (int i = 0; i < n; i ++ )
    {
        if (a[i] == 'w') cnta ++;
    }
    for (int i = 0; i < n; i ++ )
    {
        if (b[i] == 'w') cntb ++;
    }
    if (cnta != cntb)
    {
        cout << "Impossible" << endl;
    }
    else
    {
        int ans = 1;
        int ttl = 2;
        while (a != b && ttl)
        {
            
            vector<int>idx;
            for (int i = 0; i < n; i ++ )
            {
                if (a[i] != b[i]) idx.push_back(i);
            }
            for (int i = idx.size() - 1; i; i -- )
            {
                swap(a[idx[i]], a[idx[i - 1]]);
            }
            ttl --;
            ans ++;
        }
        cout << ans << endl;
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