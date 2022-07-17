#include <bits/stdc++.h>
using namespace std;

#define returnNo return void(puts("No"))
#define returnYes return void(puts("Yes"))

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p)
{
    return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
    os << '[';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << ']';
}

void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    debug_out(T...);
}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

#define int long long
#define endl '\n'
constexpr int N = 2e5 + 10;
map<char, int> mp;
void solve()
{
    string a;
    int p;
    cin >> a >> p;
    string b = a;
    sort(a.begin(), a.end());
    int sum = 0;
    map<char,int>ma;
    for (int i = 0; i < a.size(); i ++ )
    {
        sum += mp[a[i]];
        if (sum > p)
        {
            break;
        }
        ma[a[i]] ++;
    }
    for (int i = 0; i < b.size(); i ++ )
    {
        if (ma[b[i]] > 0)
        {
            ma[b[i]] --;
            cout << b[i];
        }
    }
    cout << endl;
}

signed main()
{
    for (char i = 'a'; i <= 'z'; i ++ )
    {
        mp[i] = i - 'a' + 1; 
    }
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
}