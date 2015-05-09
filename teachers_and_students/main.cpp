#include <iostream>
#include <string>
#include <vector>
#include "TeacherAndStudent.h"
using namespace std;
 
int main() {
  Teacher t1;
  Teacher t2(123412, "wh");
  Student s1;
  t1.setId(123411);
  t1.setName("hw");
  cout << t1.getId() << "-" << t1.getName() << endl;
  s1.setId(133400);
  s1.setName("st");
  cout << s1.getId() << "-" << s1.getName() << endl;
 
  int n, k;  // k < n
  cin >> n >> k;
  Student* sk = NULL;
  for (int i = 0; i < n; i++) {
    int id;
    string name;
    cin >> id >> name;
    Student* st = new Student(id, name);
    st->Register(&t2);
    if (i == k) {
      sk = st;
    }
  }
 
  t2.ShowStudents();
  t2.Logout(sk);
  t2.ShowStudents();
 
  return 0;
}
