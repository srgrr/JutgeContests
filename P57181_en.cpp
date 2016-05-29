#include <bits/stdc++.h>
using namespace std;

/*
    La pista de l'enunciat donava a entendre que l'envolupant convexa
    tindria suficients pocs punts com per a iterar de  forma cubica sobre ells.
*/

class Point    {
public:
    double x, y;

    // comparison is done first on y coordinate and then on x coordinate
    bool operator < (Point b) {
        if (y != b.y)
            return y < b.y;
        return x < b.x;
    }
};

// Point having the least y coordinate, used for sorting other points
// according to polar angle about this point
Point pivot;

// returns -1 if a -> b -> c forms a counter-clockwise turn,
// +1 for a clockwise turn, 0 if they are collinear
int ccw(Point a, Point b, Point c) {
    double area = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (area > 0)
        return -1;
    else if (area < 0)
        return 1;
    return 0;
}

// returns square of Euclidean distance between two points
double sqrDist(Point a, Point b)  {
    double dx = a.x - b.x, dy = a.y - b.y;
    return dx * dx + dy * dy;
}

double sqrtDist(Point a, Point b) {
    return sqrt(sqrDist(a,b));
}

// used for sorting points according to polar order w.r.t the pivot
bool POLAR_ORDER(Point a, Point b)  {
    double order = ccw(pivot, a, b);
    if (order == 0)
        return sqrDist(pivot, a) < sqrDist(pivot, b);
    return (order == -1);
}

stack<Point> grahamScan(Point *points, int N)    {
    stack<Point> hull;

    if (N < 3)
        return hull;

    // find the point having the least y coordinate (pivot),
    // ties are broken in favor of lower x coordinate
    int leastY = 0;
    for (int i = 1; i < N; i++)
        if (points[i] < points[leastY])
            leastY = i;

    // swap the pivot with the first point
    Point temp = points[0];
    points[0] = points[leastY];
    points[leastY] = temp;

    // sort the remaining point according to polar order about the pivot
    pivot = points[0];
    sort(points + 1, points + N, POLAR_ORDER);

    hull.push(points[0]);
    hull.push(points[1]);
    hull.push(points[2]);

    for (int i = 3; i < N; i++) {
        Point top = hull.top();
        hull.pop();
        while (ccw(hull.top(), top, points[i]) != -1)   {
            top = hull.top();
            hull.pop();
        }
        hull.push(top);
        hull.push(points[i]);
    }
    return hull;
}


int main() {
    cout.setf(ios::fixed);
    cout.precision(4);
    
    int n;
    while(cin >> n) {
        Point points[n];
        for(int i=0; i<n; ++i) cin >> points[i].x >> points[i].y;
        stack<Point> CH = grahamScan(points, n);
        vector<Point> v;
        while(not CH.empty()) {
            v.push_back(CH.top());
            CH.pop();
        }
        n = v.size();
        double maxp = 0.0;
        for(int i=0; i<n; ++i)
            for(int j=i+1; j<n; ++j)
                for(int k=j+1; k<n; ++k)
                    maxp = max(maxp, sqrtDist(v[i], v[j]) + sqrtDist(v[i],v[k]) + sqrtDist(v[j],v[k]));
        cout << maxp << endl;
    }
    
    
}