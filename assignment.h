#ifndef ASSIGNMENT_CLASS_H
#define ASSIGNMENT_CLASS_H 1

#include <string>
#include <vector>

#include "assignmentSolution.h"

using std::string;
using std::vector;

struct Assignment {
  string courseName;
  string courseCode;

  int studentId;

  vector<AssignmentSolution> assignmentSolutions;
};

#endif