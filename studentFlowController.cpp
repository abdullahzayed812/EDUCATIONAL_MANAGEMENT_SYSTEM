#include "studentFlowController.h"

#include <iostream>
#include <memory>
#include <string>

#include "coursesManager.h"
#include "helper.h"
// #include "student.h"
#include "assignmentSolution.h"
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
    } else if (choice == 2) {
      this->listCourses();
    } else if (choice == 3) {
      this->viewCourse();
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

void StudentFlowController::listCourses() {
  int pos;

  std::cout << "\nMy courses list: \n";

  for (std::shared_ptr<Course> course : this->currentStudent->registeredCourses) {
    std::cout << "\t" << ++pos << " - with code: " << course->name;
    std::cout << "\t course code: " << course->code << "\n";
  }
}

void StudentFlowController::viewCourse() {
  if (this->currentStudent->registeredCourses.size() == 0) {
    std::cout << "\nNo registered courses\n";
    return;
  }

  this->listCourses();

  int coursesCount = (int)this->currentStudent->registeredCourses.size();

  std::cout << "\n\tWhich ith [1 - " << coursesCount << "] course to view: ";

  int choice = Helper::readInt(1, coursesCount);

  this->currentCourse = this->currentStudent->registeredCourses[choice];

  std::cout << "\n\tCourse name: " << this->currentCourse->name << "\t with code: " << this->currentCourse->code
            << "\n";
  std::cout << "\tTaught by doctor: " << this->currentCourse->doctor->name << "\n";
  std::cout << "\tCourse has " << this->currentCourse->assignments.size() << " assignments: \n";

  int pos = 0;

  for (std::shared_ptr<Assignment> assignment : this->currentCourse->assignments) {
    std::cout << "\t\tAssignment - " << ++pos << " : ";

    std::shared_ptr<AssignmentSolution> assignmentSolution = this->currentStudent->getAssignmentSolution(assignment);

    if (assignmentSolution == nullptr) {
      std::cout << "NOT submitted - NA";
    } else {
      std::cout << "submitted ";

      if (assignmentSolution->isGraded) {
        std::cout << assignmentSolution->grade;
      } else {
        std::cout << "NA";
      }
    }

    std::cout << " / " << assignment->maxGrade << "\n";
  }
}
