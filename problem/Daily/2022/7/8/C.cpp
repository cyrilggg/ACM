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
    int r, c;
    cin >> r >> c;
    if (r == 1 && c == 1) cout << 0 << endl;
    else if (r == 1)
    {
        for (int i = 1; i <= c; i ++ )
        {
            cout << i + 1 << " \n"[i == c];
        }
    }
    else if (c == 1)
    {
        for (int i = 1; i <= r; i ++ )
        {
            cout << i + 1 << "\n";
        }
    }
    else
    {
        vector<vector<int>> v(r + 1, vector<int>(c + 1));
        
        int idx = 2;
        
        for (int i = 2; i <= c; i ++ ) v[0][i] = idx ++;
        idx = c + 1;
        for (int i = 1; i <= r; i ++ ) v[i][1] = idx ++;
    
        for (int i = 1; i <= r; i ++ )
        {
            for (int j = 2; j <= c; j ++ )
            {
                v[i][j] = v[i][1] * v[0][j];
            }
        }
        for (int i = 1; i <= r; i ++ )
        {
            for (int j = 1; j <= c; j ++ )
            {
                cout << v[i][j] << " \n"[j == c];
            }
        }
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