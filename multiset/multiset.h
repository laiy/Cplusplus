#ifndef MULTISET_H
#define MULTISET_H

#include <iostream>
#include <map>
using std::map;
using std::ostream;
using std::endl;

template <typename T>
class MultiSet {
    public:
        MultiSet() {}
        MultiSet(const MultiSet& set);
        MultiSet& operator=(const MultiSet& set);
        void insert(const T& ele);
        bool erase(const T& ele);
        MultiSet Union(const MultiSet&  set);
        MultiSet Intersection(const MultiSet& set);
        template <typename T1>
        friend ostream& operator<<(ostream& out, const MultiSet<T1>& set);
    private:
        map<T, int> my_map;
};
#endif
