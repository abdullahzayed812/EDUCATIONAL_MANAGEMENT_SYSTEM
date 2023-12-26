#ifndef COURSE_CLASS_H
#define COURSE_CLASS_H 1

#include <string>
#include <vector>

#include "assignment.h"

using std::string;
using std::vector;

struct Course {
  string name;
  string code;

  vector<Assignment> courseAssignments;
};

#endif