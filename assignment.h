#ifndef ASSIGNMENT_CLASS_H
#define ASSIGNMENT_CLASS_H 1

#include <memory>
#include <string>
#include <vector>

#include "course.h"

using std::shared_ptr;
using std::string;
using std::vector;

struct AssignmentSolution;

struct Assignment {
  string content;
  int maxGrade;

  shared_ptr<Course> course;
  vector<shared_ptr<AssignmentSolution>> assignmentSolutions;
};

#endif