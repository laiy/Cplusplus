#include "TeacherAndStudent.h"

Teacher::Teacher() {}

Teacher::Teacher(int id, const string& name) {
    this->id_ = id;
    this->name_ = name;
}

Teacher::~Teacher() {
    students_.clear();
}

const string& Teacher::getName() const {
    return this->name_;
}

int Teacher::getId() const {
    return this->id_;
}

/*
* show format :
* "[id]-[name] teacher has [n] students : { [sid]-[sname] [sid]-[sname] ... }"
*/
void Teacher::ShowStudents() const {
  vector<Student*>::const_iterator it = students_.begin();
  cout << getId() << "-" << getName() << " teacher has " << students_.size() << " students : { ";
  while (it != students_.end()) {
      cout << (*it)->getId() << "-" << (*it)->getName() << " ";
      it++;
  }
  cout << "}" << endl;
}

/*
* register format :
* "[id]-[name] registers success!"
*/
void Teacher::Register(Student* student) {
    this->students_.push_back(student);
    cout << student->getId() << "-" << student->getName() << " registers success!" << endl;
}

/*
* logout format :
* if success :
* "[id]-[name] logouts success!"
* else :
* "[id]-[name] is not found!"
*/
void Teacher::Logout(Student* student) {
  vector<Student*>::iterator it = students_.begin();
  bool found = false;
  while (it != students_.end()) {
      if (*it == student) {
          students_.erase(it);
          found = true;
          cout << student->getId() << "-" << student->getName() << " logouts success!" << endl;
          break;
      }
      it++;
  }
  if (!found)
      cout << student->getId() << "-" << student->getName() << " is not found!" << endl;
}

void Teacher::setId(int id) {
    this->id_ = id;
}

void Teacher::setName(const string& name) {
    this->name_ = name;
}

