const double EPS = 1e-12;

struct Point{
    double x, y;
    Point() : x(0.0), y(0.0){}
    Point(double x, double y) : x(x), y(y){}
    Point& operator=(const Point &p) {
        x = p.x;
        y = p.y;
        return *this;
    }
    Point& operator+=(const Point &p) {
        x += p.x;
        y += p.y;
        return *this;
    }
    Point& operator-=(const Point &p) {
        x -= p.x;
        y -= p.y;
        return *this;
    }
    Point operator+(const Point &p) const {
        return Point(x + p.x, y + p.y);
    }
    Point operator-(const Point &p) const {
        return Point(x - p.x, y - p.y);
    }
    bool operator<(const Point &right) const {
        return x == right.x ? y < right.y : x < right.x;
    }
    double dot(const Point &p) const {
        return x * p.x + y * p.y;
    }
    double cross(const Point &p) const {
        return x * p.y - y * p.x;
    }
    double arg() {
        return atan2(y, x);
    }
    double norm2() {
        return x * x + y * y;
    }
    double norm() {
        return sqrt(norm2());
    }
    void out(){
        cout << x << " " << y << endl;
    }
};

class Circle {
    public:
        double x, y, r;
        Circle(double cx, double cy, double cr) {
            x = cx;
            y = cy;
            r = cr;
        }
        pair<Point, Point> intersections(Circle c) {
            Point P0(x, y);
            Point P1(c.x, c.y);
            double d, a, h;
            d = P0.distance(P1);
            a = (r*r - c.r*c.r + d*d)/(2*d);
            h = sqrt(r*r - a*a);
            Point P2 = P1.sub(P0).scale(a/d).add(P0);
            double x3, y3, x4, y4;
            x3 = P2.x + h*(P1.y - P0.y)/d;
            y3 = P2.y - h*(P1.x - P0.x)/d;
            x4 = P2.x - h*(P1.y - P0.y)/d;
            y4 = P2.y + h*(P1.x - P0.x)/d;

            return pair<Point, Point>(Point(x3, y3), Point(x4, y4));
        }
};

// a -> b -> c
int dir(point a, point b, point c){
    b -= a;
    c -= a;
    if (b.cross(c) > EPS) return 1;     // counter clockwise
    if (b.cross(c) < EPS) return -1;    // clockwise
    return 0;
}

vector<point> convex_hull(vector<point> &ps){
    int n = ps.size(), k = 0;
    sort(ALL(ps));
    vector<point> ch(2 * n, point(1, 1));
    for (int i = 0; i < n; ch[k++] = ps[i++]){
        while (k >= 2 && dir(ch[k-2], ch[k-1], ps[i]) <= 0) k--;
    }
    for (int i = n - 2, t = k + 1; i >= 0; ch[k++] = ps[i--]){
        while (k >= t && dir(ch[k-2], ch[k-1], ps[i]) <= 0) k--;
    }
    ch.resize(k - 1);
    return ch;
}

// 線分AB,CDの交差判定 交点 A + r*(B-A) = C + s*(D-C)
bool intersect(double xa, double ya, double xb, double yb, double xc, double yc, double xd, double yd){
    double g = (xb - xa)*(yd - yc) - (yb - ya)*(xd - xc);
    if (fabs(g) < EPS) return false;
    double r = ((yd - yc)*(xc - xa) - (xd - xc)*(yc - ya)) / g;
    double s = ((yb - ya)*(xc - xa) - (xb - xa)*(yc - ya)) / g;
    if (r < 0 || r > 1 || s < 0 || s > 1) return false;
    return true;
}