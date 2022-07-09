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
//#define endl '\n'
constexpr int N = 2e5 + 10;

bool check(pair<int, int> p)
{
    
    cout << "?" << ' ' << p.first << ' ' << p.second << endl;
    vector<int>v;
    int cnt = 0;
    for (int i = p.first; i <= p.second; i ++ )
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    for (auto &vv : v)
    {
        if (vv >= p.first && vv <= p.second) cnt ++;
    }
    return !(cnt & 1);
}

void solve()
{
    int n;
    cin >> n;
    int l = 1, r = n;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check({l, mid})) l = mid + 1 ;
        else r = mid;
    }
    // cout << "?" << ' ' << l << ' ' << l << endl;
    // int x;
    // cin >> x;
    // if (x == l)
    // cout <<"!" << ' '<< l << endl;
    // else
    cout <<"!" << ' '<< r << endl;
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