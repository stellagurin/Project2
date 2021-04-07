#include<string>

using namespace std;

#include <iostream>
#include "Student.h"

Student::Student(){
    id = 0;
    name = "";
}

Student::Student(int sid, string sname){
  id = sid;
  name = sname;
}

void Student::setStudentId(int sid){
  id = sid;
}

void Student::setStudentName(string sname){
  name = sname;
}

int Student::getStudentId(){
    return id;
}

string Student::getStudentName(){
    return name;
}

bool Student::operator==(const Student &other) const{
    return (id == other.id);
}

bool Student::operator>(const Student &other) const{
    return (id > other.id);
}

bool Student::operator<(const Student &other) const {
    return (id < other.id);
}
