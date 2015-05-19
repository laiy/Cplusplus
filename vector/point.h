#ifndef POINT_H
#define POINT_H
 
#include <iostream>
#include <cstdio>
using std::ostream;
 
class Point {
    public:
        Point(double i = 0, double j = 0):x(i), y(j) {}
        Point(const Point& p) {
                x = p.x;
                y = p.y;
        }
        Point& operator=(const Point& p) {
                x = p.x;
                y = p.y;
                return *this;
        }
        Point operator+(const Point& p) const {
                Point ans;
                ans.x = x + p.x;
                ans.y = y + p.y;
                return ans;
        }
        Point operator-(const Point& p) const {
                Point ans;
                ans.x = x - p.x;
                ans.y = y - p.y;
                return ans;
        }
        Point operator*(double d) const {
                Point ans;
                ans.x = x * d;
                ans.y = y * d;
                return ans;
        }
        Point operator/(double d) const {
                Point ans;
                ans.x = x / d;
                ans.y = y / d;
                return ans;
        }
        friend ostream& operator<<(ostream& out, const Point& p) {
                printf("(%.4lf, %.4lf)", p.x, p.y);
                return out;
        }
 
    private:
        double x;
        double y;
};
 
#endif
