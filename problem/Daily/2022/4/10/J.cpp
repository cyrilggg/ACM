#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n, m;

const double DINF = 1e18, eps = 1e-8;
struct Point
{
    double x, y;
    int idx;
    Point(double x = 0, double y = 0):x(x), y(y){ }
    bool operator< (const Point &b) const
    {
        return atan2(x, y) < atan2(b.x, b.y);
    }
    double operator ^(const Point &b)const{
    return x*b.y - y*b.x;
    }
    //点积
    double operator *(const Point &b)const{
    return x*b.x + y*b.y;
    }
}p[N];
Point st,ed;
typedef Point Vector;
Vector operator + (Vector A, Vector B){return Vector(A.x + B.x, A.y + B.y);}
//!点 - 点 = 向量(向量BC = C - B)
Vector operator - (Point A, Point B){return Vector(A.x - B.x, A.y - B.y);}
//!向量 * 数 = 向量
Vector operator * (Vector A, double p){return Vector(A.x * p, A.y * p);}
//!向量 / 数= 向量
Vector operator / (Vector A, double p){return Vector(A.x / p, A.y / p);}
//!三态函数sgn用于判断相等，减少精度误差问题
int sgn(double x){
    if(fabs(x) < eps)
        return 0;
    if(x < 0)
        return -1;
    return 1;
}

double Cross(Vector A, Vector B){return A.x *  B.y - B.x * A.y;}

//判断向量bc是不是向ab的逆时针方向（左边）转
int relation(Point A, Point B, Point C)
{
    // 1 left -1 right 0 in
    int c = sgn(Cross((B - A), (C - A)));
    if(c < 0) return 1;
    else if(c > 0) return -1;
    return 0;
}
struct Line
{
    Point s,e;
    Line(){}
    Line(Point _s,Point _e)
    {
        s = _s;
        e = _e;
    }
    Point crosspoint(Line v)
    {
        double a1 = (v.e - v.s)^(s - v.s);
        double a2 = (v.e - v.s)^(e - v.s);
        return Point((s.x*a2 - e.x*a1)/(a2 - a1),(s.y*a2 - e.y*a1)/(a2 - a1));
    }
};
int main()
{
    map<int,int>mp;
    cin >> n >> m;
    cin >> st.x >> st.y >> ed.x >> ed.y;
    for (int i = 1; i <= n; i ++ )
    {
        cin >> p[i].x >> p[i].y;
        p[i].x -= st.x;
        p[i].y -= st.y;
        p[i].idx = i;
        p[i + n].x = p[i].x;
        p[i + n].y = p[i].y;
        p[i + n].idx = i;
    }
    sort(p + 1, p + 1 + n);
    sort(p + 1 + n, p + 1 + 2 * n);
    for (int i = n + 1; i <= 2 * n; i ++ )
    {
        mp[p[i].idx] = i;
        //cout << p[i].idx << ' ' << i << endl;
    }
    while (m -- )
    {
        int h, k;
        cin >> h >> k;
        //cout <<h << ' '<< mp[h] << endl;
        //cout << p[mp[h]].x << ' ' << p[mp[h]].y << ' ' << p[mp[h] - k].x <<' '<<p[mp[h] - k].y << endl;
        if (relation(st,p[mp[h]], p[mp[h] - k]) != -1) cout << -1 << endl;
        else
        {
            Line a = Line({0, 0}, {ed.x, ed.y});
            Line b = Line({p[mp[h] - k], p[mp[h]]});
            cout <<fixed << setprecision(8) << a.crosspoint(b).x + st.x << ' ' << a.crosspoint(b).y + st.y << endl;
        }
    }
}
