#include "Student.h"
#include <iostream>
#include <cstring>
#include <iomanip>

int Student::numStudents = 0;

Student::Student(const char *name) {
    this->name = new char[strlen(name) + 1];
    this->grades = new int[100];
    size_t i;
    for (i = 0; i < strlen(name); i++) this->name[i] = name[i];
    this->name[i] = '\0';
    this->numGrades = 0;
    numStudents++;
    std::cout << "A student has been added" << std::endl;
}

Student::~Student() {
    std::cout << this->name << " has been deleted" << std::endl;
    delete []name;
    delete []grades;
    numStudents--;
}

void Student::displayGrades() const {
    std::cout << "Here are the grades for " << name << std::endl;
    for (int i = 0; i < numGrades; i++)
        std::cout << std::setw(5) << grades[i];
    std::cout << std::endl << std::endl;
}

Student& Student::addGrade(int grade) {
    this->grades[this->numGrades++] = grade;
    return *this;
}

int Student::getNumStudents() {
    return numStudents;
}

