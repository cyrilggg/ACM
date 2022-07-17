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

#define endl '\n'
constexpr int N = 2e5 + 10;
const double DINF = 1e18, eps = 1e-36, pi = acos(-1.0);

int sgn(double x)
{
    if (fabs(x) < eps)
        return 0;
    if (x < 0)
        return -1;
    else
        return 1;
}

struct Point
{
    long double x, y;
    Point() {}
    Point(double x, double y) : x(x), y(y) {}
    void input()
    {
        scanf("%lf%lf", &x, &y);
    }
    void output()
    {
        printf("%.2f%.2f\n", x, y);
    }
    bool operator==(Point b) const
    {
        return sgn(x - b.x) == 0 && sgn(y - b.y) == 0;
    }
    bool operator<(Point b) const
    {
        return sgn(x - b.x) == 0 ? sgn(y - b.y) < 0 : x < b.x;
    }
    Point operator-(const Point &b) const
    {
        return Point(x - b.x, y - b.y);
    }
    //���
    double operator^(const Point &b) const
    {
        return x * b.y - y * b.x;
    }
    //���
    double operator*(const Point &b) const
    {
        return x * b.x + y * b.y;
    }
    Point operator*(const double &b) const
    {
        return Point(x * b, y * b);
    }
    Point operator/(const double &b) const
    {
        return Point(x / b, y / b);
    }
    Point operator+(const Point &B) const
    {
        return {x + B.x, y + B.y};
    }
    //���س���
    double len()
    {
        return hypot(x, y); //�⺯��
    }
    // �������
    double distance(Point p)
    {
        return hypot(x - p.x, y - p.y);
    }
    //���س��ȵ�ƽ��
    double len2()
    {
        return x * x + y * y;
    }
    //���� pa �� pb �ļн�
    //����������㿴 a,b ���ɵļн�
    //���� LightOJ1203
    double rad(Point a, Point b)
    {
        Point p = *this;
        return fabs(atan2(fabs((a - p) ^ (b - p)), (a - p) * (b - p)));
    }
    //��Ϊ����Ϊ r ������
    Point trunc(double r)
    {
        double l = len();
        if (!sgn(l))
            return *this;
        r /= l;
        return Point(x * r, y * r);
    }
    //��ʱ����ת 90 ��
    Point rotleft()
    {
        return Point(-y, x);
    }
    //˳ʱ����ת 90 ��
    Point rotright()
    {
        return Point(y, -x);
    }
    //���� p ����ʱ����ת angle
    Point rotate(Point p, double angle)
    {
        Point v = (*this) - p;
        double c = cos(angle), s = sin(angle);
        return Point(p.x + v.x * c - v.y * s, p.y + v.x * s + v.y * c);
    }
    // ��ȡ����
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
typedef Point Vector;
// ��������
bool cmp(const Point &o1, const Point &o2)
{

    if (o1.getQuad() == o2.getQuad())
        return (o1 ^ o2) > 0;
    else
        return o1.getQuad() < o2.getQuad();
}

inline Point FootPoint(Point p, Point a, Point b)
{ //����P��ֱ��AB�Ĵ��㡿
    Vector x = p - a, y = p - b, z = b - a;
    double len1 = x * z / z.len(), len2 = y * (-1.0) * z / z.len(); //�ֱ����AP,BP��AB,BA�ϵ�ͶӰ
    return a + z * (len1 / (len1 + len2));                          //��A��������AF
}

inline Point SymmetryPoint(Point p, Point a, Point b)
{ //����P����ֱ��AB�ĶԳƵ㡿
    return p + (FootPoint(p, a, b) - p) * 2;
    //ʵ���Ͼ�������֮���ӳ�һ���õ�����������ԭ���ĵ������������
}

struct Line
{ //ֱ�߶���
    Point s, e;
    Line() {}
    Line(Point _s, Point _e)
    {
        s = _s;
        e = _e;
    }
    bool operator==(Line v)
    {
        return (s == v.s) && (e == v.e);
    }
    Line(Point p, double angle)
    {
        s = p;
        if (sgn(angle - pi / 2) == 0)
        {
            e = (s + Point(0, 1));
        }
        else
        {
            e = (s + Point(1, tan(angle)));
        }
    }
    // ax+by+c=0
    Line(double a, double b, double c)
    {
        if (sgn(a) == 0)
        {
            s = Point(0, -c / b);
            e = Point(1, -c / b);
        }
        else if (sgn(b) == 0)
        {
            s = Point(-c / a, 0);
            e = Point(-c / a, 1);
        }
        else
        {
            s = Point(0, -c / b);
            e = Point(1, (-c - a) / b);
        }
    }
    // �߶γ���
    void input()
    {
        s.input();
        e.input();
    }
    void adjust()
    {
        if (e < s)
            swap(s, e);
    }
    double length()
    {
        return s.distance(e);
    }
    //����ֱ����б�� 0<=angle<pi
    double angle()
    {
        double k = atan2(e.y - s.y, e.x - s.x);
        if (sgn(k) < 0)
            k += pi;
        if (sgn(k - pi) == 0)
            k -= pi;
        return k;
    }
    //��ֱ�߽���
    Point crosspoint(Line v)
    {
        double a1 = (v.e - v.s) ^ (s - v.s);
        double a2 = (v.e - v.s) ^ (e - v.s);
        return Point((s.x * a2 - e.x * a1) / (a2 - a1), (s.y * a2 - e.y * a1) / (a2 - a1));
    }
    Point get_point_in_line(double t)
    { //����ֱ����һ��P = v + (p - v)*t
        Vector p = e - s;
        return e + p.trunc(t);
    }
    //�㵽ֱ�ߵľ���
    double dispointtoline(Point p)
    {
        return fabs((p - s) ^ (e - s)) / length();
    }
    //�㵽�߶εľ���
    double dispointtoseg(Point p)
    {
        if (sgn((p - s) * (e - s)) < 0 || sgn((p - e) * (s - e)) < 0)
            return min(p.distance(s), p.distance(e));
        return dispointtoline(p);
    }
    //�����߶ε��߶εľ���
    //ǰ�������߶β��ཻ���ཻ������� 0 ��
    double dissegtoseg(Line v)
    {
        if (segcrossseg(v) != 0)
            return 0; // �����ཻ
        return min(min(dispointtoseg(v.s), dispointtoseg(v.e)), min(v.dispointtoseg(s), v.dispointtoseg(e)));
    }
    //���ֱ�߹�ϵ
    // 1 �����
    // 2 ���Ҳ�
    // 3 ��ֱ����
    int relation(Point p)
    {
        int c = sgn((p - s) ^ (e - s));
        if (c < 0)
            return 1;
        else if (c > 0)
            return 2;
        else
            return 3;
    }
    bool parallel(Line v)
    {
        return sgn((e - s) ^ (v.e - v.s)) == 0;
    }
    bool pointonseg(Point p)
    {
        return sgn((p - s) ^ (e - s)) == 0 && sgn((p - s) * (p - e)) <= 0;
    }
    //��ֱ�߹�ϵ
    // 0 ƽ��
    // 1 �غ�
    // 2 �ཻ
    // 3 �ཻ�Ҵ�ֱ
    int linecrossline(Line v)
    {
        Vector a = s - e, b = v.s - v.e;
        if (sgn(a * b) == 0)
            return 3;
        if ((*this).parallel(v))
            return v.relation(s) == 3;
        return 2;
    }
    //���߶��ཻ�ж�
    // 2 �淶�ཻ
    // 1 �ǹ淶�ཻ
    // 0 ���ཻ
    int segcrossseg(Line v)
    {
        int d1 = sgn((e - s) ^ (v.s - s));
        int d2 = sgn((e - s) ^ (v.e - s));
        int d3 = sgn((v.e - v.s) ^ (s - v.s));
        int d4 = sgn((v.e - v.s) ^ (e - v.s));
        if ((d1 ^ d2) == -2 && (d3 ^ d4) == -2)
            return 2;
        return (d1 == 0 && sgn((v.s - s) * (v.s - e)) <= 0) ||
               (d2 == 0 && sgn((v.e - s) * (v.e - e)) <= 0) ||
               (d3 == 0 && sgn((s - v.s) * (s - v.e)) <= 0) ||
               (d4 == 0 && sgn((e - v.s) * (e - v.e)) <= 0);
    }
    //���ص� p ��ֱ���ϵ�ͶӰ
    Point lineprog(Point p)
    {
        return s + (((e - s) * ((e - s) * (p - s))) / ((e - s).len2()));
    }
    //���ص� p ����ֱ�ߵĶԳƵ�
    Point symmetrypoint(Point p)
    {
        Point q = lineprog(p);
        return Point(2 * q.x - p.x, 2 * q.y - p.y);
    }
};

//���ֱ�߹�ϵ
// 1 �����
//-1 ���Ҳ�
// 0 ��ֱ���� //ֱ��������s��e
// A, B:ֱ����һ��,C:���жϹ�ϵ�ĵ�
int relation(Point A, Point B, Point C)
{
    // 1 left -1 right 0 in
    int c = sgn(((B - A) ^ (C - A)));
    if (c < 0)
        return 1;
    else if (c > 0)
        return -1;
    return 0;
}
struct circle
{
    Point p;  //Բ��
    long double r; //�뾶
    bool flag;
    circle() {}
    circle(Point _p, double _r)
    {
        p = _p;
        r = _r;
    }
    circle(double x, double y, double _r)
    {
        p = Point(x, y);
        r = _r;
    }
    //�����ε����Բ
    //��Ҫ Point �� + / rotate() �Լ� Line �� crosspoint()
    //���������ߵ��д��ߵõ�Բ��
    circle(Point a, Point b, Point c)
    {
        Line u = Line((a + b) / 2, ((a + b) / 2) + ((b - a).rotleft()));
        Line v = Line((b + c) / 2, ((b + c) / 2) + ((c - b).rotleft()));
        p = u.crosspoint(v);
        r = p.distance(a);
    }
    //�����ε�����Բ
    //���� bool t û�����ã�ֻ��Ϊ�˺��������Բ��������
    circle(Point a, Point b, Point c, bool t)
    {
        Line u, v;
        double m = atan2(b.y - a.y, b.x - a.x), n = atan2(c.y - a.y, c.x - a.x);
        u.s = a;
        u.e = u.s + Point(cos((n + m) / 2), sin((n + m) / 2));
        v.s = b;
        m = atan2(a.y - b.y, a.x - b.x), n = atan2(c.y - b.y, c.x - b.x);
        v.e = v.s + Point(cos((n + m) / 2), sin((n + m) / 2));
        p = u.crosspoint(v);
        r = Line(a, b).dispointtoseg(p);
    }
    void input()
    {
        p.input();
        scanf("%lf", &r);
    }
    void output()
    {
        printf("%.2lf-%.2lf-%.2lf\n", p.x, p.y, r);
    }
    bool operator==(circle v)
    {
        return (p == v.p) && sgn(r - v.r) == 0;
    }
    bool operator<(circle v) const
    {
        return ((p < v.p) || ((p == v.p) && sgn(r - v.r) < 0));
    }
    //���
    double area()
    {
        return pi * r * r;
    }
    //�ܳ�
    double circumference()
    {
        return 2 * pi * r;
    }
    //���Բ�Ĺ�ϵ
    // 0 Բ��
    // 1 Բ��
    // 2 Բ��
    int relation(Point b)
    {
        double dst = b.distance(p);
        if (sgn(dst - r) < 0)
            return 2;
        else if (sgn(dst - r) == 0)
            return 1;
        return 0;
    }
    //�߶κ�Բ�Ĺ�ϵ
    //�Ƚϵ���Բ�ĵ��߶εľ���Ͱ뾶�Ĺ�ϵ
    int relationseg(Line v)
    {
        double dst = v.dispointtoseg(p);
        if (sgn(dst - r) < 0)
            return 2;
        else if (sgn(dst - r) == 0)
            return 1;
        return 0;
    }
    //ֱ�ߺ�Բ�Ĺ�ϵ
    //�Ƚϵ���Բ�ĵ�ֱ�ߵľ���Ͱ뾶�Ĺ�ϵ
    int relationline(Line v)
    {
        double dst = v.dispointtoline(p);
        if (sgn(dst - r) < 0)
            return 2;
        else if (sgn(dst - r) == 0)
            return 1;
        return 0;
    }
    //��Բ�Ĺ�ϵ
    // 5 ����
    // 4 ����
    // 3 �ཻ
    // 2 ����
    // 1 �ں�
    //��Ҫ Point �� distance
    int relationcircle(circle v)
    {
        double d = p.distance(v.p);
        if (sgn(d - r - v.r) > 0)
            return 5;
        if (sgn(d - r - v.r) == 0)
            return 4;
        double l = fabs(r - v.r);
        if (sgn(d - r - v.r) < 0 && sgn(d - l) > 0)
            return 3;
        if (sgn(d - l) == 0)
            return 2;
        if (sgn(d - l) < 0)
            return 1;
    }
    //������Բ�Ľ��㣬���� 0 ��ʾû�н��㣬���� 1 ��һ�����㣬2 ����������
    //��Ҫ relationcircle
    int pointcrosscircle(circle v, Point &p1, Point &p2)
    {
        int rel = relationcircle(v);
        if (rel == 1 || rel == 5)
            return 0;
        double d = p.distance(v.p);
        double l = (d * d + r * r - v.r * v.r) / (2 * d);
        double h = sqrt(r * r - l * l);
        Point tmp = p + (v.p - p).trunc(l);
        p1 = tmp + ((v.p - p).rotleft().trunc(h));
        p2 = tmp + ((v.p - p).rotright().trunc(h));
        if (rel == 2 || rel == 4)
            return 1;
        return 2;
    }
    //��ֱ�ߺ�Բ�Ľ��㣬���ؽ������
    int pointcrossline(Line v, Point &p1, Point &p2)
    {
        if (!(*this).relationline(v))
            return 0;
        Point a = v.lineprog(p);
        double d = v.dispointtoline(p);
        d = sqrt(r * r - d * d);
        if (sgn(d) == 0)
        {
            p1 = a;
            p2 = a;
            return 1;
        }
        p1 = a + (v.e - v.s).trunc(d);
        p2 = a - (v.e - v.s).trunc(d);
        return 2;
    }
    //�õ��� a,b ���㣬�뾶Ϊ r1 ������Բ
    int gercircle(Point a, Point b, double r1, circle &c1, circle &c2)
    {
        circle x(a, r1), y(b, r1);
        int t = x.pointcrosscircle(y, c1.p, c2.p);
        if (!t)
            return 0;
        c1.r = c2.r = r;
        return t;
    }
    //�õ���ֱ�� u ���У����� q, �뾶Ϊ r1 ��Բ
    int getcircle(Line u, Point q, double r1, circle &c1, circle &c2)
    {
        double dis = u.dispointtoline(q);
        if (sgn(dis - r1 * 2) > 0)
            return 0;
        if (sgn(dis) == 0)
        {
            c1.p = q + ((u.e - u.s).rotleft().trunc(r1));
            c2.p = q + ((u.e - u.s).rotright().trunc(r1));
            c1.r = c2.r = r1;
            return 2;
        }

        Line u1 = Line((u.s + (u.e - u.s).rotleft().trunc(r1)), (u.e + (u.e - u.s).rotleft().trunc(r1)));
        Line u2 = Line((u.s + (u.e - u.s).rotright().trunc(r1)), (u.e + (u.e - u.s).rotright().trunc(r1)));
        circle cc = circle(q, r1);
        Point p1, p2;
        if (!cc.pointcrossline(u1, p1, p2))
            cc.pointcrossline(u2, p1, p2);
        c1 = circle(p1, r1);
        if (p1 == p2)
        {
            c2 = c1;
            return 1;
        }
        c2 = circle(p2, r1);
        return 2;
    }
    //ͬʱ��ֱ�� u,v ���У��뾶Ϊ r1 ��Բ
    int getcircle(Line u, Line v, double r1, circle &c1, circle &c2, circle &c3, circle &c4)
    {
        if (u.parallel(v))
            return 0; //��ֱ��ƽ��
        Line u1 = Line(u.s + (u.e - u.s).rotleft().trunc(r1), u.e + (u.e - u.s).rotleft().trunc(r1));
        Line u2 = Line(u.s + (u.e - u.s).rotright().trunc(r1), u.e + (u.e - u.s).rotright().trunc(r1));
        Line v1 = Line(v.s + (v.e - v.s).rotleft().trunc(r1), v.e + (v.e - v.s).rotleft().trunc(r1));
        Line v2 = Line(v.s + (v.e - v.s).rotright().trunc(r1), v.e + (v.e - v.s).rotright().trunc(r1));
        c1.r = c2.r = c3.r = c4.r = r1;
        c1.p = u1.crosspoint(v1);
        c2.p = u1.crosspoint(v2);
        c3.p = u2.crosspoint(v1);
        c4.p = u2.crosspoint(v2);
        return 4;
    }
    //ͬʱ�벻�ཻԲ cx,cy ���У��뾶Ϊ r1 ��Բ
    int getcircle(circle cx, circle cy, double r1, circle &c1, circle &c2)
    {
        circle x(cx.p, r1 + cx.r), y(cy.p, r1 + cy.r);
        int t = x.pointcrosscircle(y, c1.p, c2.p);
        if (!t)
            return 0;
        c1.r = c2.r = r1;
        return t;
    }

    //��һ����Բ������ (���жϵ��Բ�Ĺ�ϵ)
    int tangentline(Point q, Line &u, Line &v)
    {
        int x = relation(q);
        if (x == 2)
            return 0;
        if (x == 1)
        {
            u = Line(q, q + (q - p).rotleft());
            v = u;
            return 1;
        }
        double d = p.distance(q);
        double l = r * r / d;
        double h = sqrt(r * r - l * l);
        u = Line(q, p + ((q - p).trunc(l) + (q - p).rotleft().trunc(h)));
        v = Line(q, p + ((q - p).trunc(l) + (q - p).rotright().trunc(h)));
        return 2;
    }
    //����Բ�ཻ�����
    double areacircle(circle v)
    {
        int rel = relationcircle(v);
        if (rel >= 4)
            return 0.0;
        if (rel <= 2)
            return min(area(), v.area());
        double d = p.distance(v.p);
        double hf = (r + v.r + d) / 2.0;
        double ss = 2 * sqrt(hf * (hf - r) * (hf - v.r) * (hf - d));
        double a1 = acos((r * r + d * d - v.r * v.r) / (2.0 * r * d));
        a1 = a1 * r * r;
        double a2 = acos((v.r * v.r + d * d - r * r) / (2.0 * v.r * d));
        a2 = a2 * v.r * v.r;
        return a1 + a2 - ss;
    }
    //��Բ�������� pab ���ཻ���
    double areatriangle(Point a, Point b)
    {
        if (sgn((p - a) ^ (p - b)) == 0)
            return 0.0;
        Point q[5];
        int len = 0;
        q[len++] = a;
        Line l(a, b);
        Point p1, p2;
        if (pointcrossline(l, q[1], q[2]) == 2)
        {
            if (sgn((a - q[1]) * (b - q[1])) < 0)
                q[len++] = q[1];
            if (sgn((a - q[2]) * (b - q[2])) < 0)
                q[len++] = q[2];
        }
        q[len++] = b;
        if (len == 4 && sgn((q[0] - q[1]) * (q[2] - q[1])) > 0)
            swap(q[1], q[2]);
        double res = 0;
        for (int i = 0; i < len - 1; i++)
        {
            if (relation(q[i]) == 0 || relation(q[i + 1]) == 0)
            {
                double arg = p.rad(q[i], q[i + 1]);
                res += r * r * arg / 2.0;
            }
            else
            {
                res += fabs((q[i] - p) ^ (q[i + 1] - p)) / 2.0;
            }
        }
        return res;
    }
};

struct dsu
{
    // normal
    int n;
    int fa[N];
    int sz[N];
    dsu(int _n) : n(_n)
    {
        for (int i = 1; i <= n; ++i)
        {
            fa[i] = i;
            sz[i] = 1;
        }
    }
    int Find(int x)
    {
        return fa[x] == x ? x : fa[x] = Find(fa[x]);
    }
    void Union(int x, int y)
    {
        int fx = Find(x);
        int fy = Find(y);
        if (fx == fy)
        {
            return;
        }
        if (sz[fx] > sz[fy])
        {
            swap(fx, fy);
        }
        sz[fy] += sz[fx];
        fa[fx] = fy;
    }
};

void solve()
{
    int n;
    cin >> n;
    long double sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    Point st = {sx, sy}, ed = {tx, ty};
    vector<circle>v(n + 1);
    int stflag, edflag;
    dsu DSU(n);
    for (int i = 1; i <= n; i ++ )
    {
        long double x, y, r;
        cin >> x >> y >> r;
        circle c = {Point(x, y), r};
        c.flag = false;
        //cout << c.relation(st) <<' '<<c.relation(ed) << endl;
        if (c.relation(st) == 1)
        {
            stflag = i;
        }
        if (c.relation(ed) == 1)
        {
            edflag = i;
        }
         v[i] = c;
    }

    for (int i = 1; i <= n; i ++ ){
        for (int j = i + 1; j <= n; j ++ )
        {
            if (v[i].relationcircle(v[j]) != 5 && v[i].relationcircle(v[j]) != 1)
            {
                DSU.Union(i, j);
            }
        }
    }
    if (DSU.Find(stflag) == DSU.Find(edflag)) cout << "Yes" << endl;
    else cout << "No" << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
}