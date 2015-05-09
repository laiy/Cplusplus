#include "TeacherAndStudent.h"

Student::Student() {}

Student::Student(int id, const string& name) {
    this->id_ = id;
    this->name_ = name;
}

Student::~Student() {}

const string& Student::getName() const {
    return this->name_;
}

int Student::getId() const {
    return this->id_;
}

void Student::Register(Teacher* teacher) {
    teacher->Register(this);
}

void Student::setId(int id) {
    this->id_ = id;
}

void Student::setName(const string& name) {
    this->name_ = name;
}

