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
constexpr int N = 2e5 + 10;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>>v(n + 1, vector<int>(m + 1));
    v[1][1] = 1;
    int tag = 2, ntag = 0;
    for (int i = 2; i <= n; i ++ )
    {
        if (tag > 0){
            v[i][1] = 0;
            tag --;
        
        if (tag == 0)
        {
            ntag = 2;
        }
        }
        else
        {
            v[i][1] = 1;
            ntag --;
            if (ntag == 0)
            {
                tag = 2;
            }
        }
    }
    tag = ntag = 0;
    for (int i = 1; i <= n; i ++ )
    {
        if (v[i][1] == 1) ntag = 2;
        else tag = 2; 
        for (int j = 2; j <= m; j ++ )
        {
            if (tag > 0)
            {
                v[i][j] = 1;
                tag --;
                if (tag == 0)
                {
                    ntag = 2;
                }
            }
            else
            {
                v[i][j] = 0;
                ntag --;
                if (ntag == 0)
                {
                    tag = 2;
                }
            }

        }
        ntag = tag = 0;
    }
    for (int i = 1; i <= n; i ++ )
    {
        for (int j = 1; j <= m; j ++ )
        {
            cout << v[i][j] << " \n"[j == m];
        }
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