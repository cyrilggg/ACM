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

void solve(int _)
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n + 2);
    int cnt = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i].first;
        v[i].second = i;
        q.push(v[i]);
    }
    v[0] = {-1, 0};
    v[n + 1] = {-1, 0};
    map<int, int> mp;
    for (int i = 0; i <= n + 1; i++)
        mp[i] = 1;
    while (q.size())
    {
        auto t = q.top();
        q.pop();
        //    cout << t.first << ' ' << t.second << ' ' << mp[t.second - 1] << ' ' << mp[t.second + 1] << endl;
        //    if (mp[t.second - 1] != 0 && mp[t.second + 1] != 0)
        //    {
        //        mp[t.second] = 0;
        //        cnt += t.first;
        //    }
        //    else
        //    {
        //        mp[t.second] = 1;
        //        cnt += t.first - 1;
        //    }
        int MI = -1;
        if (v[t.second].first > v[t.second - 1].first)
            MI = max(MI, v[t.second - 1].first);
        if (v[t.second].first > v[t.second + 1].first)
            MI = max(MI, v[t.second + 1].first);
        MI++;
        cnt += v[t.second].first - MI;
        v[t.second].first = MI;
    }
    debug(cnt);
    cout << "Case " << _ << ": ";
    if (cnt & 1)
        cout << "Alice" << endl;
    else
        cout << "Bob" << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int _ = 1;
    cin >> _;
    for (int i = 1; i <= _; i++)
        solve(i);
}