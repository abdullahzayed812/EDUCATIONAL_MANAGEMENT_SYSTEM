#ifndef DOCTOR_CLASS_H
#define DOCTOR_CLASS_H 1

#include <memory>
#include <string>
#include <vector>

#include "course.h"

using std::shared_ptr;
using std::string;
using std::vector;

struct Doctor {
  string username;
  string password;
  string name;
  string email;

  vector<shared_ptr<Course>> teachingCourses;
};

#endif