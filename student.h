#ifndef STUDENT_CLASS_H
#define STUDENT_CLASS_H 1

#include <memory>
#include <string>
#include <vector>

#include "course.h"

using std::shared_ptr;
using std::string;
using std::vector;

struct Student {
  string username;
  string password;
  string name;
  string email;

  int id;

  vector<shared_ptr<Course>> registeredCourses;
};

#endif