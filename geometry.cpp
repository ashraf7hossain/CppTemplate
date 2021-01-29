 
const double pi = acos(-1);
 
inline double sqr(double x){
  return x*x;
}
const double eps = 1e-9;
 
 
struct Point {
  using db = double;
    db x, y;
    Point(db _x = 0, db _y = 0) : x(_x), y(_y) {}
    Point operator+(const Point& r) const { return Point(x + r.x, y + r.y); }
    Point operator-(const Point& r) const { return Point(x - r.x, y - r.y); }
    db operator^(const Point& r) const { return x * r.y - y * r.x; }
    Point operator*(const db& r) const { return Point(x * r, y * r); }
    Point operator*(const Point& r) const{
      return x*r.x + y*r.y;
    }
    Point operator/(const db& r) const{
      return Point(x/r, y/r);
    }
    bool operator==(const Point& r) const{
      return x==r.x&&y==r.y;
    }
    Point rotate(db ag) { return Point(x*cos(ag)-y*sin(ag),x*sin(ag)+y*cos(ag)); }
    void input() { scanf("%lf %lf", &x, &y); }
    db len2() { return sqr(x) + sqr(y); }
    db len() { return sqrt(len2()); }
    db dist(Point r) { return ((*this)-r).len(); }
    db ang() { return atan2(y, x); }
    Point norm() {return *this/len();}
    db len(Point r){
      return sqr(x-r.x)+sqr(y-r.y);
    }
    void output() { printf("%lf %lf\n", x, y); }
    
};
 
double dst(Point a, Point b){
  return sqr(a.x-b.x)+sqr(a.y-b.y);
}
bool eq(double x, double y){return fabs(x-y)<eps;}
bool IntersectLines(Point A, Point a, Point B, Point b, Point& M){
  if(eq(a^b,0))return false;
  double y = ((A-B)^(a))/(b^a);
  M = B + b*y;
  return true;
 
}
 
Point LineSeg(Point p0, Point p1, Point p2, Point p3){
  double a1 = p1.y - p0.y;
  double a2 = p3.y - p2.y;
  double b1 = p0.x - p1.x;
  double b2 = p2.x - p3.x;
  double c1 = a1*p0.x + b1*p0.y;
  double c2 = a2*p2.x + b2*p2.y;
  Point a = {a1,b1}, b = {a2,b2};
  double det = a^b;
  if(det==0)return {2e18,2e18};
  double x = (Point(b2,c2)^Point(b1,c1));
  double y = Point(a1,c1)^Point(a2,c2);
  double X = x/det, Y = y/det;
  
  double rx0 =(X-p0.x)/(p1.x-p0.x);
  double ry0 =(Y-p0.y)/(p1.y-p0.y);
  
  double rx1 =(X-p2.x)/(p3.x-p2.x);
  double ry1 =(Y-p2.y)/(p3.y-p2.y);
  
  if(((rx0>=0&&rx0<=1) || (ry0>=0&&ry0<=1))&&
     ((rx1>=0&&rx1<=1) || (ry1>=0&&ry1<=1))){
    return {X,Y};
  }
  else return {2e18,2e18};
  
}
double get_angle(p a, p b){
  return atan2(a.y - b.y,a.x-b.x);
}
void sortByangle(vector<Point>&v ,Point center){
	auto cmp = [&](Point a , Point b){
		double g1 = get_angle(center,a),g2 = get_angle(center,b);
                  return g1<g2;
             };
	sort(all(v),cmp);
}
 
