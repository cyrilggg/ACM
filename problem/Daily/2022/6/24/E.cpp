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
    int n, ss;
    cin >> n >> ss;
    vector<int>v(n + 1), s(n + 1);
    v.push_back(0);
    for (int i = 1; i <= n; i ++ )
    {
        cin >> v[i];
        s[i] = s[i - 1] + v[i];
    }
    int sum = accumulate(v.begin() + 1, v.end(), 0);
    if(sum < ss)
    {
        cout << -1 << endl;
        return;
    }
    if (sum == ss)
    {
        cout << 0 << endl;
        return;
    }
    int start = -1;
    int ans = 0;
    for (int i = 1; i <= n; i ++ )
    {
        if (s[i] == (sum - ss))
        {
            start = i;
            ans = i;
            break;
        }
    }
    int cnt = 0;
    for (int i = start - 1, j = n + 1; i < j && i >= 1; i --, j --, cnt ++ )
    {
        while (i < j && v[j] == 0)
        {
            j --;
            cnt ++;
        }
        while (i >= 1 && v[i] == 0)
        {
            i --;
        }
        debug(i, j, i + cnt);
        ans = min(ans, i + cnt);
    
    }
    cout << ans << endl;
    debug(ans);
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