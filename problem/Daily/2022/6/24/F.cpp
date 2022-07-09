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
    int n;
    cin >> n;
    vector<int>v(n + 1);
    map<int,int>mp;
    for (int i = 1; i <= n; i ++ )
    {
        int x;
        cin >> x;
        x %= 10;
        mp[x] ++;    
    }
    for (int i = 0; i <= 9; i ++ )
    {
        for (int j = 0; j <= 9; j ++ )
        {
            for (int k = 0; k <= 9; k ++ )
            {
                if (((i + j + k) % 10) == 3)
                {
                    if (i == j && j == k && mp[j] < 3) continue;
                    if (i == j && mp[i] < 2) continue;
                    if (i == k && mp[i] < 2) continue;
                    if (j == k && mp[j] < 2) continue;
                    if (mp[i] && mp[j] && mp[k])
                    returnYes;
                }
            }
        }
    }
    returnNo;
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