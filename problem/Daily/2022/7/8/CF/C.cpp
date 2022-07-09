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

map<int,int>mp;
int n, m;

bool check(int x)
{
    int cnt = 0;
    for (auto &[a, b] : mp)
    {
        if (b >= x) cnt += x;
        else cnt += b + (x - b) / 2;
    }
    return cnt >= m;
}

void solve()
{
    cin >> n >> m;
    mp.clear();
    for (int i = 1; i <= n; i ++ )
    {
        mp[i] = 0;
    }
    for (int i = 1; i <= m; i ++ )  {
        int x;
        cin >> x;
        mp[x] ++;
    }
    int l = 0, r = 1e9;
    while (l < r)
    {
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    for (int i = l - 1; i <= r; i ++ )
    {
        if (check(i))
        {
            cout << i << endl;
            return;
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