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

constexpr int P = 998244353, N = 5e5 + 10;
using i64 = long long;

int norm(int x) 
{
    if (x < 0) {
        x += P;
    }
    if (x >= P) {
        x -= P;
    }
    return x;
}

template<class T>
T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}

struct Z {
    int x;
    Z(int x = 0) : x(norm(x)) {}
    Z(i64 x) : x(norm((int)(x % P))) {}
    int val() const {
        return x;
    }
    Z operator-() const {
        return Z(norm(P - x));
    }
    Z inv() const {
        assert(x != 0);
        return power(*this, P - 2);
    }
    Z &operator*=(const Z &rhs) {
        x = i64(x) * rhs.x % P;
        return *this;
    }
    Z &operator+=(const Z &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    Z &operator-=(const Z &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    Z &operator/=(const Z &rhs) {
        return *this *= rhs.inv();
    }
    friend Z operator*(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res *= rhs;
        return res;
    }
    friend Z operator+(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res += rhs;
        return res;
    }
    friend Z operator-(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res -= rhs;
        return res;
    }
    friend Z operator/(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res /= rhs;
        return res;
    }
};

int work(vector<int>v, int l, int r, int x)
{
    Z ans = 1;
    int cnt = 0;
    if (x == 1)
    {
        for (int i = l; i <= r; i ++ )
        {
            int ccnt = 0;
            while (i <= r && v[i] == 1)
            {
                ccnt ++;
                i ++;
            }
            cnt += (1 + ccnt) * ccnt / 2; 
        }
        return cnt;
    }
    for (int i = l, j = l; i <= r; i ++ )
    {
        if (v[i - 1] == 1) cnt += j - i;
        else
        {
          while (j <= r && ans.val() < x)
          {
             ans *= v[j];
             j ++;
          }
          if (ans.val() == x) cnt ++;
          while (j <= r && ans.val() == x && v[j] == 1)
          {
             cnt ++;
             ans *= v[j];
             j ++;
          }
        }
      if (v[i])ans /= v[i];
   }
    return cnt;
}

void solve()
{
   int n, x;
   cin >> n >> x;
   vector<int>v(n + 1);
   for (int i = 1; i <= n; i ++ )
      cin >> v[i];
   Z ans = 1;
   int cnt = 0;
    int l = 1;
    if (x == 0){
        queue<int>q;
        for (int i = 1; i <= n; i ++ )
        {
            if (v[i] == 0) q.push(i);
        }
        for (int i = 1; i <= n; i ++ )
        {
            if (v[i])
            {
                cnt += q.size();
            }
            else
            {
                q.pop();
                cnt += n - i + 1;
            }
        }
    }
    else{
        for (int i = 1; i <= n; i ++ )
        {
            if (v[i] == 0)
            {
                if (i != 1 && l <= i - 1)
                {
                    cnt += work(v, l, i - 1, x);
                }
                if (i != n)l = i + 1;
            }
        }
        if (l <= n)cnt += work(v, l, n, x);
    }
    cout << cnt << endl;
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
