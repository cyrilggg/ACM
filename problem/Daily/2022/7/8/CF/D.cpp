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
constexpr int N = 5e5 + 10;

void solve()
{
    int n;
    cin >> n;
    vector<int>v(n + 1), ans(n + 1);
    vector<int>l(n + 1), r (n + 1);
    for (int i = 1; i <= n; i ++ ){
        cin >> v[i];
    }
    for (int i = 1; i <= n; i ++ )
    {
        if (v[i] == 0){
            l[i] = i + 1, r[i] = n;
        }
        else{
            l[i] = i / (v[i] + 1) + 1, r[i] = i / v[i];
        }
    }
    vector<vector<int>>vv(n + 1);
    for (int i = 1; i <= n; i ++ ){
        vv[l[i]].push_back(i);
    }
    set<pair<int,int>>S;
    for (int i = 1; i <= n; i ++ ){
        for (auto &j : vv[i])
        {
            S.emplace(r[j], j);
        }
        assert(!S.empty());
        ans[S.begin() -> second] = i;
        S.erase(S.begin());
    }
    for (int i = 1; i <= n; i ++ ){
        cout << ans[i] << " \n"[i == n];
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