#ifndef _TEACHER_AND_STUDENT_H_
#define _TEACHER_AND_STUDENT_H_
 
#include <iostream>
#include <string>
#include <vector>
using namespace std;
 
class Student;
 
class Teacher {
 public:
  Teacher();
  Teacher(int id, const string& name);
  ~Teacher();
 
  const string& getName() const;
  int getId() const;
 
  /*
   * show format :
   * "[id]-[name] teacher has [n] students : { [sid]-[sname] [sid]-[sname] ... }"
   */
  void ShowStudents() const;
 
  /*
   * register format :
   * "[id]-[name] registers success!"
   */
  void Register(Student* student);
 
  /*
   * logout format :
   * if success :
   * "[id]-[name] logouts success!"
   * else :
   * "[id]-[name] is not found!"
   */
  void Logout(Student* student);
  void setId(int id);
  void setName(const string& name);
 
 private:
  int id_;
  string name_;
  vector<Student*> students_;
};
 
class Student {
 public:
  Student();
  Student(int id, const string& name);
  ~Student();
 
  const string& getName() const;
  int getId() const;
 
  void Register(Teacher* teacher);
 
  void setId(int id);
  void setName(const string& name);
 
 private:
  int id_;
  string name_;
};
 
#endif  // _TEACHER_AND_STUDENT_H_
