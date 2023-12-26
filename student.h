#ifndef STUDENT_CLASS_H
#define STUDENT_CLASS_H 1

#include <string>
#include <vector>

#include "course.h"

using std::string;
using std::vector;

struct Student {
  string username;
  string password;
  string name;
  string email;

  int id;

  vector<Course> registeredCourses;
};

#endif