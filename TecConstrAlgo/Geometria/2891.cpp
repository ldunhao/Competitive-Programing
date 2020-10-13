#include <bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl;
#define watchArray(v) for(auto i : v) cout << i << ' '; cout << endl;
#define all(x) (x).begin(),(x).end()

const int INF = 0x3f3f3f3f;
const long long int MOD = 1e9-1;
const long long int MAXN = 5e3;
const long double PI = acos(-1.0);
const double QZERO = 0.000000001;
const double EPS = 1e-9;

typedef long long int lli;
typedef vector<vector<char>> matrix;

template <class T> int sgn(T x) {
	return (T(0) < x) - (x < T(0));
}

template <class T> struct Point2D { 
	T x, y;

	Point2D(T x = 0, T y = 0) : x(x), y(y) {}

	bool operator < (Point2D p) { return tie(x,y) < tie(p.x, p.y); }
	bool operator == (Point2D p) { return tie(x,y) == tie(p.x, p.y); }
	bool operator != (Point2D p) { return !(tie(x,y) == tie(p.x, p.y)); }
	Point2D operator - (Point2D p) { return Point2D(x - p.x, y - p.y); }
	Point2D operator + (Point2D p) { return Point2D(x + p.x, y + p.y); }
	Point2D operator * (T k) { return Point2D(k * x, k * y); }
	Point2D operator / (T k) { return Point2D(x / k, y / k); }

	T dot(Point2D p) { return x * p.x + y * p.y; }
	T cross(Point2D p) { return x * p.y - y * p.x; }
	T cross(Point2D a, Point2D b) const { return (a - *this).cross(b - *this); }
	T dist2() const { return x * x + y * y; }
	double dist() const { return sqrt((double)dist2()); }
	double angle() const { return atan2(y, x); } // angle to x-axis in interval [-pi, pi]
	Point2D unit() const { return *this / dist(); } // makes dist()=1
	Point2D perp() const { return Point2D(-y, x); } // rotates +90 degrees
	Point2D normal() const { return perp().unit(); }

	// Returns point rotated 'a' radians ccw around the origin
	Point2D rotate(double a) const {
		return Point2D(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
	}

	double distanceToPoint(Point2D b) {
		return sqrt(((x - b.x) * (x - b.x)) + ((y - b.y) * (y - b.y)));
	}
	
	// Returns true if this point lies on the line segment from point 's' to point'e'
	// Use (distanceToSegment(s, e) <= EPS) instead when using Point2D<double>.
	bool onSegment(Point2D s, Point2D e) {
		return (*this).cross(s, e) == 0 && (s - *this).dot(e - *this) <= 0;
	}

	// Returns the shortest distance between this point and the line segment from point s to e.
	double distanceToSegment(Point2D &s, Point2D &e) {
		if (s == e) {
			return ((*this) - s).dist();
		}

		auto d = (e - s).dist2();
		auto t = min(d, max(.0,((*this) - s).dot(e - s)));
		
		return (((*this) - s) * d - (e - s) * t).dist() / d;
	}

	// Returns the signed perpendicular distance between point p and the line containing points a and b.
	// Positive value on left side and negative on right as seen from a towards b. a==b gives nan.
	double distanceToLine(Point2D &a, Point2D &b) {
		return (double)(b - a).cross((*this) - a) / (b - a).dist();
	}

	// Returns true if p lies within the polygon. 
	// If strict is true, it returns false for points on the boundary.
	// The algorithm uses products in intermediate steps so watch out for overflow.
	bool isInsidePolygon(vector<Point2D> &polygon, bool strict = true) {
		int cnt = 0, n = int(polygon.size());

		for (int i = 0; i < n; i++) {
			Point2D q = polygon[(i + 1) % n];

			if (onSegment(polygon[i], q)) {
				return !strict;
			}
			//or: if (distanceToSegment(polygon[i], q) <= EPS) return !strict;
			cnt ^= (((*this).y < polygon[i].y) - ((*this).y < q.y)) * (*this).cross(polygon[i], q) > 0;
		}

		return cnt;
	}

	// Returns where p is as seen from s towards e. (1/0/-1) ⇔ left/on line/right.
	// If the optional argument eps is given 0 is returned if p is within distance eps from the line.
	int sideOf(Point2D s, Point2D e) { 
		return sgn(s.cross(e, (*this)));
	}

	int sideOf(Point2D &s, Point2D &e, double eps) {
		auto a = (e - s).cross((*this) - s);
		double l = (e - s).dist() * eps;

		return (a > l) - (a < -l);
	}

	friend ostream& operator << (ostream& os, Point2D p) {
		return os << "(" << p.x << "," << p.y << ")"; 
	}
};

typedef Point2D<double> P;
vector<P> ConvexHull(vector<P> pts) {
    sort(pts.begin(), pts.end());
    vector<P> h;
    for (int step = 1; step <= 2; step++) {
        int start = (int)h.size();

        for (auto p : pts) {
            while ((int)h.size() >= start + 2 && h[(int)h.size() - 2].cross(h[(int)h.size() - 1], p) < 0) {
                h.pop_back();
            }

            h.push_back(p);
        }

        h.pop_back();
        reverse(pts.begin(), pts.end());
    }

    return h;
}
double areaPolygon(vector<P> polygon) {
    double area = 0.0;

    for (int i = 0, n = polygon.size(); i < n; i++) {
        area += polygon[i].cross(polygon[(i + 1) % n]);
    }

    return abs(area) / 2.0;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

    vector<P> pontos;

    int x1,y1,x2,y2,x3,y3,x4,y4,x5,y5;

    while(true){

        cin >> x1 >> y1;pontos.push_back(P(x1,y1));
        cin >> x2 >> y2;pontos.push_back(P(x2,y2));
        cin >> x3 >> y3;pontos.push_back(P(x3,y3));
        cin >> x4 >> y4;pontos.push_back(P(x4,y4));
        cin >> x5 >> y5;pontos.push_back(P(x5,y5));

        if(x1 == 0 and y1 == 0 and x2 == 0 and y2 == 0 and x3 == 0 and y3 == 0 and x4 == 0 and y4 == 0 and x5 == 0 and y5 == 0) break;


        double ans = 0.0;
		int n = (int)pontos.size();
		for (int i = 0; i < n; i++) {
			vector<Point2D<double>> pts;
			
			pts.push_back(pontos[i]);

			int cnt = 0, j = (i + 1) % n;
	
			while (cnt < 3) {
				pts.push_back(pontos[j]);
				j = (j + 1) % n;
				cnt++;
			}

			vector<Point2D<double>> quadrilateral = ConvexHull(pts);

			if (quadrilateral.size() < 4) {
				continue;
			}
			
			double area = areaPolygon(quadrilateral);
			ans = max(ans, area);
		}

		cout << ans << endl;
		pontos.clear();
    }

    return 0;
}