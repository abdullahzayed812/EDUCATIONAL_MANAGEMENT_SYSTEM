#include "student.h"

#include <map>
#include <memory>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

#include "assignment.h"
#include "assignmentSolution.h"

std::shared_ptr<AssignmentSolution> Student::getAssignmentSolution(
    std::shared_ptr<Assignment> assignment) {
  for (std::shared_ptr<AssignmentSolution> assignmentSolution : this->assignmentSolutions) {
    if (assignmentSolution->assignment == assignment) {
      return assignmentSolution;
    }
  }

  return nullptr;
}

std::vector<std::tuple<std::string, int, int, int>> Student::computeGradesStatistic() {
  std::vector<std::tuple<std::string, int, int, int>> studentGradesStatistic;

  std::map<std::string, int> courseCodeToTotalStudentGradesSum;
  std::map<std::string, int> courseCodeToTotalAssignments;
  std::map<std::string, int> courseCodeToTotalGradesSum;

  for (std::shared_ptr<AssignmentSolution> studentAssignmentSolution : this->assignmentSolutions) {
    std::string courseCode = studentAssignmentSolution->assignment->course->code;

    if (studentAssignmentSolution->isGraded) {
      courseCodeToTotalStudentGradesSum[courseCode] += studentAssignmentSolution->grade;
    }
    courseCodeToTotalGradesSum[courseCode] += studentAssignmentSolution->assignment->maxGrade;
    courseCodeToTotalAssignments[courseCode]++;
  }

  for (std::pair<std::string, int> studentCourseGrades : courseCodeToTotalStudentGradesSum) {
    std::string courseCode = studentCourseGrades.first;

    std::tuple<std::string, int, int, int> studentGradesInfo(
        courseCode, courseCodeToTotalAssignments[courseCode],
        courseCodeToTotalStudentGradesSum[courseCode], courseCodeToTotalGradesSum[courseCode]);

    studentGradesStatistic.push_back(studentGradesInfo);
  }

  return studentGradesStatistic;
}