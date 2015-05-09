#include "smart_p.h"

template <typename T>
scoped_ptr<T>::scoped_ptr(T* p) : ptr(p) {}

template <typename T>
scoped_ptr<T>::~scoped_ptr() {
    delete ptr;
}

template <typename T>
void scoped_ptr<T>::reset(T* p) {
    if (ptr != p) {
        delete ptr;
        ptr = p;
    }
}

template <typename T>
T* scoped_ptr<T>::get() const {
    return ptr;
}

template <typename T>
T& scoped_ptr<T>::operator*() const {
    return *ptr;
}

template <typename T>
T* scoped_ptr<T>::operator->() const {
    return ptr;
}

