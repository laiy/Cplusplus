#include <iostream>
#include "smart_p.cpp"
using namespace std;
 
class DeletionTest {
  public:
    explicit DeletionTest(bool* deletion_flag) : deletion_flag_(deletion_flag) {
        *deletion_flag_ = false;
    }
 
    ~DeletionTest() {
        *deletion_flag_ = true;
    }
 
    void foo() {
        cout << "foo" << endl;
    }
 
  private:
    bool* deletion_flag_;
};
 
int main(int argc, char *argv[]) {
    // Test deletion, get and operatro->, *.
    {
        bool isDeleted = false;
        {
            // We put a pointer into a smart pointer at construction time.
            scoped_ptr<DeletionTest> d(new DeletionTest(&isDeleted));
            d.get()->foo();
            // We can call through the smart pointer as if it were a pointer.
            d->foo();
            // ... Or by *
            (*d).foo();
        }
        cout << isDeleted << endl;
    }
 
    // Reset test
    {
        int *p = new int;
        // ...Or by using reset().
        scoped_ptr<int> sp(p);  // Like "Bar* bar_ptr = NULL;
        *sp = 100;
        sp.reset(p);  // Now |bar_ptr| is non-NULL and owns the object.
        cout << (*p == 100) << endl;
    }
 
    {
        bool isDeleted = false;
        {
            bool stuff = false;
            scoped_ptr<DeletionTest> d(new DeletionTest(&isDeleted));
            d.reset(new DeletionTest(&stuff));
            cout << isDeleted << endl;
        }
    }
 
    return 0;
}
