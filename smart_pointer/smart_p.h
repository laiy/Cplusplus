#ifndef __smart_pointer__smart_p__
#define __smart_pointer__smart_p__
 
#include <iostream>
 
template <typename T>
class scoped_ptr {
  public:
    explicit scoped_ptr(T* p = 0);
    ~scoped_ptr();
 
    void reset(T* p = 0);
    T* get() const;
 
    T& operator*() const;
    T* operator->() const;
 
  private:
    T* ptr;
};
 
#endif
 
