#include <cfloat>
#include<iostream> 
#include<vector> 
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<iterator>
using namespace std;

struct Point {

    double x, y;
};

double dist(Point a, Point b) {

    double dx = a.x - b.x;
    double dy = a.y - b.y;

    return sqrt(dx * dx + dy * dy);
}

double bruteForce(
    vector<Point>& p,
    int left,
    int right
) {
    double ans = DBL_MAX;
    for(int i = left; i <= right; i++) {
        for(int j = i + 1; j <= right; j++) {
            ans = min(
                ans,
                dist(p[i], p[j])
            );
        }
    }
    return ans;
}

double stripClosest(
    vector<Point>& strip,
    double d
) {
    sort(
        strip.begin(),
        strip.end(),
        [](Point a, Point b) {
            return a.y < b.y;
        }
    );
    double ans = d;
    for(int i = 0; i < (int)strip.size(); i++) {
        for(int j = i + 1;
            j < (int)strip.size() &&
            strip[j].y - strip[i].y < ans;
            j++) {
            ans = min(
                ans,
                dist(strip[i], strip[j])
            );
        }
    }

    return ans;
}

double closestUtil(
    vector<Point>& points,
    int left,
    int right
) {
    if(right - left <= 3) {
        return bruteForce(
            points,
            left,
            right
        );
    }
    int mid =
        left + (right - left) / 2;
    Point midPoint = points[mid];
    double dl =
        closestUtil(
            points,
            left,
            mid
        );
    double dr =
        closestUtil(
            points,
            mid + 1,
            right
        );

    double d = min(dl, dr);
    vector<Point> strip;
    for(int i = left; i <= right; i++) {
        if(abs(points[i].x - midPoint.x) < d) {
            strip.push_back(points[i]);
        }
    }
    double stripDist =
        stripClosest(strip, d);
    return min(d, stripDist);
}

double closestPair(vector<Point> points) {
    sort(
        points.begin(),
        points.end(),
        [](Point a, Point b) {
            return a.x < b.x;
        }
    );
    return closestUtil(
        points,
        0,
        points.size() - 1
    );
}

int main() {
    vector<Point> points = {
        {2, 3},
        {12, 30},
        {40, 50},
        {5, 1},
        {12, 10},
        {3, 4}
    };

    cout << fixed << setprecision(6);
    cout << closestPair(points);

    return 0;
}
