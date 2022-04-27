#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define endl '\n'
const int N = 1e4 + 10, M = 2 * N;
int h[N], e[M], ne[M], idx;
int n;

constexpr int P = 998244353;
using i64 = long long;
int norm(int x) {
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
    Z(i64 x) : x(norm(x % P)) {}
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

//组合数的模
template<class T>
T qmi(T a, T k, int p)  // 快速幂模板
{
    T res = 1 % p;
    while (k)
    {
        if (k & 1) res = 1ll * res * a % p;
        a = 1ll * a * a % p;
        k >>= 1;
    }
    return res;
}

template<class T>
T C(T a, T b, int p)  // 通过定理求组合数C(a, b)
{
    if (a < b) return 0;

    T x = 1, y = 1;  // x是分子，y是分母
    for (int i = a, j = 1; j <= b; i --, j ++ )
    {
        x = 1ll * x * i % p;
        y = 1ll * y * j % p;
    }

    return x * 1ll * qmi(y, T(p - 2), p) % p;
}

template<class T>
T lucas(T a, T b)
{
    if (a < P && b < P) return C(a, b, P);
    return 1ll * C(a % P, b % P, P) * lucas(a / P, b / P) % P;
}
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
Z ans = 1;
int siz[N];
void dfs(int u)
{
    siz[u] = 1;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        dfs(j);
        siz[u] += siz[j];
    }
    int tot = siz[u] - 1;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        //cout << tot << ' ' << siz[j] << ' ' << u <<' '<< j <<  endl;
        ans *= lucas(tot, siz[j]);
        tot -= siz[j];
    }
}

void solve()
{
    memset(h, -1, sizeof h);
    cin >> n;
    for (int i = 1; i <= n; i ++ )  siz[i] = 1;
    for (int i = 2; i <= n; i ++ )
    {
        int x;
        cin >> x;
        add(x, i);
    }
    dfs(1);
    cout << ans.val() << endl;
}

signed main()
{
   int t = 1;
   //cin >> t;
   while (t -- )solve();
}