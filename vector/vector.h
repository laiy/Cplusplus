#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include "point.h"

class Vector {
    public:
        Vector(Point& a, Point& b) : begin(a), end(b) {}
        Vector& operator=(const Vector& v) {
            begin = v.begin;
            end = v.end;
            return *this;
        }
        Vector operator+(const Vector& a) const {
            Vector ans = *this;
            ans.end = end + a.end - a.begin;
            return ans;
        }
        Vector operator-(const Vector& v) const {
            Vector ans = *this;
            ans.end = end - v.end + v.begin;
            return ans;
        }
        friend Vector operator*(const Vector& v, double d) {
            Vector ans = v;
            ans.end = ans.begin + (v.end - v.begin) * d;
            return ans;
        }
        friend Vector operator*(double d, const Vector& v) {
            Vector ans = v;
            ans.end = ans.begin + (v.end - v.begin) * d;
            return ans;
        }
        Vector operator/(double d) {
            return *this * (1.0 / d);
        }
        friend ostream& operator<<(ostream& out, const Vector& v) {
            out << "from " << v.begin << " to " << v.end;
            return out;
        }
    private:
        Point begin;
        Point end;
};

#endif

