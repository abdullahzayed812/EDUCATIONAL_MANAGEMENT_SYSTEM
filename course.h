#ifndef COURSE_CLASS_H
#define COURSE_CLASS_H 1

#include <memory>
#include <string>
#include <vector>

using std::shared_ptr;
using std::string;
using std::vector;

struct Student;
struct Assignment;
struct Doctor;

struct Course {
  string name;
  string code;

  vector<shared_ptr<Student>> registeredStudents;
  vector<shared_ptr<Assignment>> assignments;
  shared_ptr<Doctor> doctor;
};

#endif