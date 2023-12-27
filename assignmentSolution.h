#ifndef ASSIGNMENT_SOLUTION_CLASS_H
#define ASSIGNMENT_SOLUTION_CLASS_H 1

#include <memory>
#include <string>

#include "assignment.h"
#include "student.h"

using std::shared_ptr;
using std::string;

struct AssignmentSolution {
  int grade;
  string answer;
  string studentId;

  shared_ptr<Assignment> assignment;
  shared_ptr<Student> student;
};

#endif