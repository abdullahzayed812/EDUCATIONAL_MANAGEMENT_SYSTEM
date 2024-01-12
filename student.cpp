#include "student.h"

#include <memory>

#include "assignment.h"
#include "assignmentSolution.h"

std::shared_ptr<AssignmentSolution> Student::getAssignmentSolution(std::shared_ptr<Assignment> assignment) {
  for (std::shared_ptr<AssignmentSolution> assignmentSolution : this->assignmentSolutions) {
    if (assignmentSolution->assignment == assignment) {
      return assignmentSolution;
    }
  }

  return nullptr;
}