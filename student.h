#ifndef STUDENT_CLASS_H
#define STUDENT_CLASS_H 1

#include <memory>
#include <string>
#include <vector>

#include "assignmentSolution.h"
#include "course.h"

using std::shared_ptr;
using std::string;
using std::vector;

struct Student {
  string username;
  string password;
  string name;
  string email;
  string id;

  std::vector<std::shared_ptr<Course>> registeredCourses;
  std::vector<std::shared_ptr<AssignmentSolution>> assignmentSolutions;

  std::shared_ptr<AssignmentSolution> getAssignmentSolution(std::shared_ptr<Assignment> assignment);
};

#endif