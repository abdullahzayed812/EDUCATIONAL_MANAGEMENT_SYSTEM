#include "studentFlowController.h"

#include <iostream>
#include <memory>
#include <string>

#include "coursesManager.h"
#include "helper.h"
// #include "student.h"
#include "course.h"
#include "doctor.h"
#include "studentsManager.h"

std::shared_ptr<StudentFlowController> gStudentFlowController(new StudentFlowController());

bool StudentFlowController::isValidUser(std::string username, std::string password) {
  return gStudentsManager->getUser(username, password) != nullptr;
}

void StudentFlowController::takeControl(std::string username, std::string password) {
  this->currentStudent = gStudentsManager->getUser(username, password);

  std::cout << "\t\t\t******* Welcome " << currentStudent->name << " *******\n\n";

  this->showMainMenu();
}

void StudentFlowController::showMainMenu() {
  vector<string> menu = {"Register in Course", "List My Courses", "View Course", "Grades Report", "Log out"};

  while (true) {
    int choice = Helper::runMenu(menu);

    if (choice == 1) {
      this->registerInCourse();
    }
  }
}

void StudentFlowController::registerInCourse() {
  std::vector<std::shared_ptr<Course>> availableCourses =
      gCoursesManager->getComplementCourses(this->currentStudent->registeredCourses);

  std::cout << "\nAvailable courses for you: \n\t";

  int pos = 0;

  for (std::shared_ptr<Course> course : availableCourses) {
    std::cout << ++pos << " - Course name: " << course->name << "\twith code: " << course->code
              << "\ttaught by doctor: " << course->doctor << "\n\t";
  }

  std::cout << "\n\tEnter course number [1 - " << availableCourses.size() << "]: ";

  int choice = Helper::readInt(1, (int)availableCourses.size());

  availableCourses[choice - 1]->registeredStudents.push_back(this->currentStudent);
  this->currentStudent->registeredCourses.push_back(availableCourses[choice - 1]);

  std::cout << "\n!!! REGISTERED SUCCESSFULLY !!!\n";
}