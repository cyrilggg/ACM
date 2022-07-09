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

bool check(pair<int,int>p)
{
    string a = to_string(p.first), b = to_string(p.second);
    if (a.size() == 1) a = '0' + a;
    if (b.size() == 1) b = '0' + b;
    if (a[0] == b[1] && a[1] == b[0])
    {
        //cout << (a + b) << endl;
        return 1;
    }
    return 0;
}

void solve()
{
    int nn, mm, tt;
    scanf("%lld:%lld %lld", &nn, &mm, &tt);
    set<pair<int,int>>S;
    pair<int,int>time = {nn, mm};
    int ans = 0;
    while (true)
    {
        if (S.count(time)) break;
        S.insert(time);
        ans += check(time);
        time.second += tt % 60;
        if (time.second > 59) time.second -= 60, time.first += 1;
        time.first += tt / 60;
        if (time.first > 23) time.first -= 24;
    }
    cout << ans << endl;
}

signed main()
{
   int _ = 1;
   cin >> _;
   while (_--)
      solve();
}