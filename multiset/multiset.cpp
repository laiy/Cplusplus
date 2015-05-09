#include "multiset.h"
#include <map>

template <typename T>
MultiSet<T>::MultiSet(const MultiSet& set) {
    this->my_map = set.my_map;
}

template <typename T>
MultiSet<T>& MultiSet<T>::operator=(const MultiSet& set) {
    this->my_map = set.my_map;
    return *this;
}

template <typename T>
void MultiSet<T>::insert(const T& ele) {
    my_map[ele] = (my_map[ele]) ? my_map[ele] + 1 : 1;
}

template <typename T>
bool MultiSet<T>::erase(const T& ele) {
    if (!my_map.count(ele)) return false;
    my_map[ele]--;
    if (!my_map[ele]) {
        typename map<T, int>::iterator it = my_map.find(ele);
        my_map.erase(it);
    }
    return true;
}

template <typename T>
MultiSet<T> MultiSet<T>::Union(const MultiSet& set) {
    MultiSet<T> temp;
    for (typename map<T,int>::iterator it = this->my_map.begin(); it != this->my_map.end(); it++)
        for (int i = 0; i < it->second; i++)
            temp.insert(it->first);
    for (typename map<T,int>::const_iterator it = set.my_map.begin(); it != set.my_map.end(); it++)
        for (int i = 0; i < it->second; i++)
            temp.insert(it->first);
    return temp;
}

template <typename T>
MultiSet<T> MultiSet<T>::Intersection(const MultiSet& set) {
    MultiSet<T> temp;
    typename map<T, int>::iterator it1 = this->my_map.begin();
    typename map<T, int>::const_iterator it2 = set.my_map.begin();
    while (it1 != this->my_map.end() && it2 != set.my_map.end()) {
        if (it1->first == it2->first) {
            int min = (it1->second < it2->second) ? it1->second : it2->second;
            for (int i = 0; i < max; i++)
                temp.insert(it1->first);
            it1++;
            it2++;
        } else if (it1->first < it2->first) {
            it1++;
        } else {
            it2++;
        }
    }
    return temp;
}

template <typename T>
ostream& operator<<(ostream& out, const MultiSet<T>& set) {
    typename map<T, int>::const_iterator it = set.my_map.begin();
    out << "{";
    if (set.my_map.size() == 0) {
        out << "}" << endl;
        return out;
    }
    for (int i = 0; i < set.my_map.size(); i++) {
        for (int j = 0; j + 1 < it->second; j++)
            out << it->first << ",";
        if (i + 1 == set.my_map.size())
            out << it->first << "}" << endl;
        else
            out << it->first << ",";
        it++;
    }
}

