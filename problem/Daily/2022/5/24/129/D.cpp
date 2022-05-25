#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
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

vector<int> mul(vector<int> &A, int b)
{
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size() || t; i++)
    {
        if (i < A.size())
            t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
    while (C.size() > 1 && C.back() == 0)
        C.pop_back();

    return C;
}


void solve()
{
    int n;
    string x;
    cin >> n >> x;
    vector<int>A;
    for (int i = x.size() - 1; i >= 0; i--)
    {
        A.push_back(x[i] - '0');
    }
    int cnt = 0;
    queue<pair<vector<int>,int>>q;
    q.push({A, 0});
    map<vector<int>,bool>mp;
    mp[A] = 1;
    while (q.size())
    {
        auto t = q.front();
        q.pop();
        if (t.first.size() > n) continue;
        if (t.first.size() == n)
        {
            cout << t.second << endl;
            return;
        }
        for (int i = 0; i < t.first.size(); i ++ )
        {
            auto C = mul(t.first, t.first[i]);
            if (C.size() >= t.first.size() && mp[C] == 0)
            {
                q.push({C, t.second + 1});
                mp[C] = 1;
            }
        }
    }
    cout << -1 << endl;
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