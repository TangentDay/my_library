const double EPS = 1e-10;

// 線分AB,CDの交差判定 交点 A + r*(B-A) = C + s*(D-C)
bool intersect(double xa, double ya, double xb, double yb, double xc, double yc, double xd, double yd){
    double g =  (xb - xa)*(yd - yc) - (yb - ya)*(xd - xc);
    if (fabs(g) < EPS) return false;
    double r = ((yd - yc)*(xc - xa) - (xd - xc)*(yc - ya)) / g;
    double s = ((yb - ya)*(xc - xa) - (xb - xa)*(yc - ya)) / g;
    if (r < 0 || r > 1 || s < 0 || s > 1) return false;
    return true;
}