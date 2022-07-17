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

struct Point
{
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {} //构造函数
    int getQuad() const
    {
        if (x > 0 && y >= 0)
            return 1;
        if (x <= 0 && y > 0)
            return 2;
        if (x < 0 && y <= 0)
            return 3;
        if (x >= 0 && y < 0)
            return 4;
        assert(false);
    }
};

//!注意区分点和向量
typedef Point Vector;

Vector operator+(Vector A, Vector B) { return Vector(A.x + B.x, A.y + B.y); }
//!点 - 点 = 向量(向量BC = C - B)
Vector operator-(Point A, Point B) { return Vector(A.x - B.x, A.y - B.y); }
//!向量 * 数 = 向量
Vector operator*(Vector A, double p) { return Vector(A.x * p, A.y * p); }
//!向量 / 数= 向量
Vector operator/(Vector A, double p) { return Vector(A.x / p, A.y / p); }

//!点/向量的比较函数
bool operator<(const Point &a, const Point &b) { return a.x < b.x || (a.x == b.x && a.y < b.y); }

Point rotate(Point A, Point p, double angle)
{
    Point v = A - p;
    double c = cos(angle), s = sin(angle);
   // cout << c << ' ' << s << endl;
    return Point(p.x + v.x * c - v.y * s, p.y + v.x * s + v.y * c);
}

void solve()
{
   double a, b, d;
   cin >> a >> b >> d;
   Point A = {a, b};
   Vector ans = rotate(A, {0, 0},  d *  acos(-1) / 180);
   cout << fixed << setprecision(7) << ans.x << ' ' << ans.y << endl; 
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