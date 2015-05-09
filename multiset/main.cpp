#include <iostream>
#include "multiset.cpp"

using std::cin;
using std::cout;

int main() {
    MultiSet<int> set1;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            set1.insert(k);
        }
    cout << set1;

    MultiSet<int> set2 = set1;
    cout << set2;
    for (int i = 0; i < m; i++) {
            int k;
            cin >> k;
            cout << set2.erase(k) << endl;
        }
    cout << set2;
    cout << set1.Union(set2);
    cout << set1.Intersection(set2);
    cout << set2.Intersection(set1);

    return 0;
}
