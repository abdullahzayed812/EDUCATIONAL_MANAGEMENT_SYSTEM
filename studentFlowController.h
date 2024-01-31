#ifndef STUDENT_FLOW_CONTROLLER_CLASS_H
#define STUDENT_FLOW_CONTROLLER_CLASS_H 1

#include <memory>
#include <string>

#include "course.h"
#include "student.h"

struct StudentFlowController {
  std::shared_ptr<Course> currentCourse;
  std::shared_ptr<Student> currentStudent;

  bool isValidUser(std::string username, std::string password);
  void takeControl(std::string username, std::string password);
  void showMainMenu();
  void registerInCourse();
  void listCourses();
  void viewCourse();
  void showCourseMenu();
  void unregisterFromCourse();
  void submitCourseAssignment();
  void showGradesReport();
};

extern std::shared_ptr<StudentFlowController> gStudentFlowController;

#endif