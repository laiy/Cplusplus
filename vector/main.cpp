#include <iostream>
#include "vector.h"
 
using std::cin;
using std::cout;
using std::endl;
 
int main() {
    double a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    Point p0(a, b), p1(c, d), p2(e, f);
    Vector v1(p0, p1), v2(p1, p2);
    cout << v1 << endl << v2 << endl;
    cout << v1 + v2 << endl;
    cout << v1 - v2 << endl;
    cout << 3 * v1 * 0.5 << endl;
    cout << v1 / 3 << endl;
    return 0;
}
 
