const double EPS = 1e-12;

struct point{
    double x, y;
    point() : x(0.0), y(0.0){}
    point(double x, double y) : x(x), y(y){}
    point& operator=(const point &p) {
        x = p.x;
        y = p.y;
        return *this;
    }
    point& operator+=(const point &p) {
        x += p.x;
        y += p.y;
        return *this;
    }
    point& operator-=(const point &p) {
        x -= p.x;
        y -= p.y;
        return *this;
    }
    point operator+(const point &p) const {
        return point(x + p.x, y + p.y);
    }
    point operator-(const point &p) const {
        return point(x - p.x, y - p.y);
    }
    bool operator<(const point &right) const {
        return x == right.x ? y < right.y : x < right.x;
    }
    double dot(const point &p) const {
        return x * p.x + y * p.y;
    }
    double cross(const point &p) const {
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
    double g =  (xb - xa)*(yd - yc) - (yb - ya)*(xd - xc);
    if (fabs(g) < EPS) return false;
    double r = ((yd - yc)*(xc - xa) - (xd - xc)*(yc - ya)) / g;
    double s = ((yb - ya)*(xc - xa) - (xb - xa)*(yc - ya)) / g;
    if (r < 0 || r > 1 || s < 0 || s > 1) return false;
    return true;
}