#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define endl '\n'
constexpr int P = 998244353;
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
        cout << lhs.val() << ' '<< rhs.val() << endl;
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
T qmi(T a, T k)  // 快速幂模板
{
    T res = 1 % P;
    while (k)
    {
        if (k & 1) res = 1ll * res * a % P;
        a = 1ll * a * a % P;
        k >>= 1;
    }
    return res;
}

template<class T>
T C(T a, T b)  // 通过定理求组合数C(a, b)
{
    if (a < b) return 0;

    T x = 1, y = 1;  // x是分子，y是分母
    for (int i = a, j = 1; j <= b; i --, j ++ )
    {
        x = 1ll * x * i % P;
        y = 1ll * y * j % P;
    }

    return x * 1ll * qmi(y, T(P - 2)) % P;
}

template<class T>
T lucas(T a, T b)
{
    if (a < P && b < P) return C(a, b);
    return 1ll * C(a % P, b % P) * lucas(a / P, b / P) % P;
}

void solve()
{
    i64 n, m, k;
    cin >> n >> m >> k;
    vector<int>v(n);
    for (int i = 0; i < n; i ++ )
        cin >> v[i];
    sort(v.begin(), v.end());
    Z ans = 0;
    for (int i = 0; i < n; i++) {
        int l = i + 1;
        int r = upper_bound(v.begin(), v.end(), v[i] + k) - v.begin();
        ans = (ans + lucas(r - l * 1ll, m - 1));
    }
    cout << ans.val() << "\n";
}

signed main()
{
   int _ = 1;
   cin >> _;
   while ( _-- )solve();
}